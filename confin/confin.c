#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "cftype.h" // confin/cftype.h
#include "cfio.h" // confin/cfio.h
#include "cfutils.h" // confin/cfutils.h

/* cfio implementation */

void confin_write_config(const char *filename, cfentry_t *entries, uint32_t entrycount) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("fopen");
        return;
    }

    cfheader_t header = {__CONFIN_STRUCT_MAGIC_NUMBER, __CONFIN_STRUCT_VERSION, entrycount};
    fwrite(&header, sizeof(cfheader_t), 1, file);

    for (uint32_t i = 0; i < entrycount; ++i) {
        fwrite(&entries[i], sizeof(cfentry_t) - sizeof(void*), 1, file);
        fwrite(entries[i].value, entries[i].size, 1, file);
    }

    fclose(file);
}

void confin_write_config_file(const char *filename, cffile_t *file) {
    return confin_write_config(filename, file->entries, file->header.entrycount);
}

cffile_t *confin_read_config(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return NULL;
    }

    cfheader_t header;
    fread(&header, sizeof(cfheader_t), 1, file);
    
    if (header.magic != __CONFIN_STRUCT_MAGIC_NUMBER) {
        fprintf(stderr, "Invalid magic number\n");
        fclose(file);
        return NULL;
    }

    cffile_t *config = (cffile_t*)malloc(sizeof(cfheader_t) + sizeof(cfentry_t) * header.entrycount);
    if (!config) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    config->header = header;
    for (uint32_t i = 0; i < header.entrycount; ++i) {
        fread(&config->entries[i], sizeof(cfentry_t) - sizeof(void*), 1, file);

        config->entries[i].value = malloc(config->entries[i].size);
        if (!config->entries[i].value) {
            perror("malloc");
            fclose(file);
            free(config);
            return NULL;
        }

        fread(config->entries[i].value, config->entries[i].size, 1, file);
    }

    fclose(file);
    return config;
}

/* cfutils implementation */

cfentry_t confin_create_config_entry(const char *key, cfannotype_t type, const void *value, uint32_t size) {
    cfentry_t entry;
    strncpy(entry.key, key, __CONFIN_STRUCT_MAX_KEYLEN - 1);
    entry.key[__CONFIN_STRUCT_MAX_KEYLEN - 1] = '\0'; // Ensure null-termination
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
    printf("Key: %s, Type: %u, Size: %u\n", entry->key, entry->type, entry->size);

    switch (entry->type) {
        case CONFIN_ANNOTYPE_INT:
            printf("Value: %d\n", *(int*)entry->value);
            break;
        case CONFIN_ANNOTYPE_FLOAT:
            printf("Value: %f\n", *(float*)entry->value);
            break;
        case CONFIN_ANNOTYPE_STRING:
            printf("Value: %s\n", (char*)entry->value);
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