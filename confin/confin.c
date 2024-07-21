#ifdef __cplusplus
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#endif

#include "cftype.h" // confin/cftype.h
#include "cfio.h" // confin/cfio.h
#include "cfutils.h" // confin/cfutils.h
#include "cffmt.h" // confin/cffmt.h

/* cfio implementation */

void confin_write_config(const char *filename, cfentry_t *entries, uint64_t entrycount) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        return;
    }

    cfheader_t header = {__CONFIN_STRUCT_MAGIC_NUMBER, _CF_VER, entrycount};
    fwrite(&header, sizeof(cfheader_t), 1, file);

    for (uint32_t i = 0; i < entrycount; ++i) {
        fwrite(&entries[i], sizeof(cfentry_t) - sizeof(void*), 1, file);
        fwrite(entries[i].value, entries[i].size, 1, file);
    }

    fclose(file);
}

void confin_write_config_file(const char *filename, cffile_t *file) {
    confin_write_config(filename, file->entries, file->header.entrycount);
}

cffile_t *confin_read_config(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return NULL;
    }

    cfheader_t header;
    size_t items_read;

    items_read = fread(&header, sizeof(cfheader_t), 1, file);

    cffile_t *config = (cffile_t*)malloc(sizeof(cfheader_t) + sizeof(cfentry_t) * header.entrycount);
    if (!config) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    config->header = header;
    for (uint32_t i = 0; i < header.entrycount; ++i) {
        items_read = fread(&config->entries[i], sizeof(cfentry_t) - sizeof(void*), 1, file);

        config->entries[i].value = malloc(config->entries[i].size);
        if (!config->entries[i].value) {
            perror("malloc");
            fclose(file);
            free(config);
            return NULL;
        }

        items_read = fread(config->entries[i].value, config->entries[i].size, 1, file);
    }
    (void)items_read;
    fclose(file);
    return config;
}

/* cfutils implementation */

cfentry_t confin_create_config_entry(const char *key, cfannotype_t type, const void *value, uint64_t size) {
    cfentry_t entry;
    #ifdef _MSC_VER
    strncpy_s(entry.key, sizeof(entry.key), key, _TRUNCATE);
    #else
    strncpy(entry.key, key, __CONFIN_STRUCT_MAX_KEYLEN - 1);
    entry.key[__CONFIN_STRUCT_MAX_KEYLEN - 1] = '\0'; // Ensure null-termination
    #endif
    entry.type = type;
    entry.size = size;
    entry.value = malloc(size);
    if (entry.value) {
        memcpy(entry.value, value, size);
    } else {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    return entry;
}

void confin_free_config_entry(cfentry_t *entry) {
    if (entry->value) {
        free(entry->value);
        entry->value = NULL;
    }
}

void confin_display_config_entry(const cfentry_t *entry) {
    printf("Key: %s, Type: %u, Size: %llu\n", entry->key, entry->type, (unsigned long long int)entry->size);

    switch (entry->type) {
        case CONFIN_ANNOTYPE_INT:
            printf("Value: %d\n", CF_UNREF_ENTRYVAL(entry->value, int));
            break;
        case CONFIN_ANNOTYPE_FLOAT:
            printf("Value: %f\n", CF_UNREF_ENTRYVAL(entry->value, float));
            break;
        case CONFIN_ANNOTYPE_STRING:
            printf("Value: %s\n", CF_REF_ENTRYVAL(entry->value, char));
            break;
        default:
            printf("Unknown type\n");
            break;
    }
}

void confin_free_config_file(cffile_t *config) {
    for (uint32_t i = 0; i < config->header.entrycount; ++i) {
        confin_free_config_entry(&config->entries[i]);
    }
    free(config);
}

/* cffmt implementation */

bool confin_validate_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return 0;
    }

    cfheader_t header;
    size_t items_read;
    items_read = fread(&header, sizeof(cfheader_t), 1, file);

    if (header.magic != __CONFIN_STRUCT_MAGIC_NUMBER) {
        fprintf(stderr, "Invalid magic number\n");
        fclose(file);
        return 0;
    }

    if (header.version > _CF_VER) {
        // Unable to read confin format when the version of the confin library used in the file is higher than the current one, update the library
        fprintf(stderr, "Invalid version\n");
        fclose(file);
        return 0;
    }

    cffile_t *config = (cffile_t*)malloc(sizeof(cfheader_t) + sizeof(cfentry_t) * header.entrycount);
    if (!config) {
        perror("malloc");
        fclose(file);
        return 0;
    }

    config->header = header;
    for (uint32_t i = 0; i < header.entrycount; ++i) {
        items_read = fread(&config->entries[i], sizeof(cfentry_t) - sizeof(void*), 1, file);

        config->entries[i].value = malloc(config->entries[i].size);
        if (!config->entries[i].value) {
            perror("malloc");
            fclose(file);
            free(config);
            return 0;
        }

        items_read = fread(config->entries[i].value, config->entries[i].size, 1, file);
    }

    fclose(file);

    // Free allocated memory
    for (uint32_t i = 0; i < header.entrycount; ++i) {
        free(config->entries[i].value);
    }
    free(config);
    (void)items_read;
    return 1;
}

bool confin_scan_file(const char *filename, char *output, size_t output_size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return false;
    }

    cfheader_t header;
    size_t items_read;
    items_read = fread(&header, sizeof(cfheader_t), 1, file);

    if (header.magic != __CONFIN_STRUCT_MAGIC_NUMBER) {
        snprintf(output, output_size, "Invalid magic number\n");
        fclose(file);
        return false;
    }

    cffile_t *config = (cffile_t*)malloc(sizeof(cfheader_t) + sizeof(cfentry_t) * header.entrycount);
    if (!config) {
        perror("malloc");
        fclose(file);
        return false;
    }

    config->header = header;
    for (uint32_t i = 0; i < header.entrycount; ++i) {
        items_read = fread(&config->entries[i], sizeof(cfentry_t) - sizeof(void*), 1, file);

        config->entries[i].value = malloc(config->entries[i].size);
        if (!config->entries[i].value) {
            perror("malloc");
            fclose(file);
            free(config);
            return false;
        }

        items_read = fread(config->entries[i].value, config->entries[i].size, 1, file);
    }

    fclose(file);

    // Prepare the output string
    char *ptr = output;
    size_t remaining_size = output_size;
    int written;

    written = snprintf(ptr, remaining_size, "Magic number: 0x%X\n", config->header.magic);
    ptr += written;
    remaining_size -= written;

    written = snprintf(ptr, remaining_size, "Version: %u [%u.%u]\n",
                       config->header.version,
                       __CONFIN_GET_MAJOR_VERSION(config->header.version),
                       __CONFIN_GET_MINOR_VERSION(config->header.version));
    ptr += written;
    remaining_size -= written;

    written = snprintf(ptr, remaining_size, "Confin version: %u [%u.%u]\n",
                       _CF_VER,
                       __CONFIN_MAJOR_VERSION,
                       __CONFIN_MINOR_VERSION);
    ptr += written;
    remaining_size -= written;

    written = snprintf(ptr, remaining_size, "Entry count: %llu\n", (unsigned long long)config->header.entrycount);
    ptr += written;
    remaining_size -= written;

    for (uint32_t i = 0; i < config->header.entrycount; ++i) {
        written = snprintf(ptr, remaining_size, "Entry %u:\n", i + 1);
        ptr += written;
        remaining_size -= written;

        written = snprintf(ptr, remaining_size, "  Key: %s\n", config->entries[i].key);
        ptr += written;
        remaining_size -= written;

        written = snprintf(ptr, remaining_size, "  Size: %llu\n", (unsigned long long)config->entries[i].size);
        ptr += written;
        remaining_size -= written;

        written = snprintf(ptr, remaining_size, "  Value: ");
        ptr += written;
        remaining_size -= written;

        for (uint32_t j = 0; j < config->entries[i].size; ++j) {
            written = snprintf(ptr, remaining_size, "%02X ", ((unsigned char*)config->entries[i].value)[j]);
            ptr += written;
            remaining_size -= written;
        }

        written = snprintf(ptr, remaining_size, "\n");
        ptr += written;
        remaining_size -= written;
    }

    // Free allocated memory
    for (uint32_t i = 0; i < header.entrycount; ++i) {
        free(config->entries[i].value);
    }
    free(config);
    (void)items_read;
    return true;
}
