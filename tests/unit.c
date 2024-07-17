#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../confin/cfstruct.h"
#include "../confin/cftype.h"
#include "../confin/cfio.h"
#include "../confin/cfutils.h"
#include "../confin/cffmt.h"

// Function to create sample entries
void create_sample_entries(cfentry_t *entries, uint32_t *entry_count) {
    int int_value = 42;
    float float_value = 3.14f;
    const char *string_value = "Hello, World!";

    entries[0] = cfcreatecfgentry("int_key", CONFIN_ANNOTYPE_INT, &int_value, sizeof(int_value));
    entries[1] = cfcreatecfgentry("float_key", CONFIN_ANNOTYPE_FLOAT, &float_value, sizeof(float_value));
    entries[2] = cfcreatecfgentry("string_key", CONFIN_ANNOTYPE_STRING, string_value, strlen(string_value) + 1);

    *entry_count = 3;
}

// Test for writing and reading configuration file
void test_write_read_config() {
    cfentry_t entries[3];
    uint32_t entry_count;
    create_sample_entries(entries, &entry_count);

    // Write configuration to file
    cfwritecfg("config_test.bin", entries, entry_count);

    // Free entries after writing to file
    for (uint32_t i = 0; i < entry_count; ++i) {
        cffreecfgentry(&entries[i]);
    }

    // Read configuration from file
    cffile_t *config = cfreadcfg("config_test.bin");
    assert(config != NULL);
    assert(config->header.entrycount == entry_count);

    // Validate the read entries
    assert(strcmp(config->entries[0].key, "int_key") == 0);
    assert(config->entries[0].type == CONFIN_ANNOTYPE_INT);
    assert(config->entries[0].size == sizeof(int));
    assert(*(int*)config->entries[0].value == 42);

    assert(strcmp(config->entries[1].key, "float_key") == 0);
    assert(config->entries[1].type == CONFIN_ANNOTYPE_FLOAT);
    assert(config->entries[1].size == sizeof(float));
    assert(*(float*)config->entries[1].value == 3.14f);

    assert(strcmp(config->entries[2].key, "string_key") == 0);
    assert(config->entries[2].type == CONFIN_ANNOTYPE_STRING);
    assert(config->entries[2].size == strlen("Hello, World!") + 1);
    assert(strcmp((char*)config->entries[2].value, "Hello, World!") == 0);

    // Free the configuration file structure
    cffreecfgfile(config);
}

// Test for validating configuration file format
void test_validate_config() {
    // Valid
    {
        cfentry_t entries[3];
        uint32_t entry_count;
        create_sample_entries(entries, &entry_count);

        // Write configuration to file
        cfwritecfg("config_test.bin", entries, entry_count);

        // Validate the configuration file format
        bool is_valid = cfvalidatefile("config_test.bin");
        assert(is_valid == true);

        // Free entries after writing to file
        for (uint32_t i = 0; i < entry_count; ++i) {
            cffreecfgentry(&entries[i]);
        }
    }
    // Valid & Empty
    {
        cfentry_t entries[1];
        uint32_t entry_count = 0;

        // Write configuration to file
        cfwritecfg("config_test_empty.bin", entries, entry_count);

        // Validate the configuration file format
        bool is_valid = cfvalidatefile("config_test_empty.bin");
        assert(is_valid == true);

        // Free entries after writing to file
        for (uint32_t i = 0; i < entry_count; ++i) {
            cffreecfgentry(&entries[i]);
        }
    }
    // Not valid
    {
        printf("Validation of an incorrect file: ");
        const char *filename = "empty_file.bin";
        // Open the file for writing in binary mode
        FILE *file = fopen(filename, "wb");

        // Check if the file was opened successfully
        if (file == NULL) {
            perror("Error opening file");
            return;
        }

        // Close the file
        fclose(file);

        // Validate the configuration file format
        bool is_valid = cfvalidatefile("empty_file.bin");
        assert(is_valid == false);
    }
}

// Test for creating and freeing configuration entries
void test_create_free_entries() {
    int int_value = 42;
    cfentry_t int_entry = cfcreatecfgentry("int_key", CONFIN_ANNOTYPE_INT, &int_value, sizeof(int_value));

    assert(strcmp(int_entry.key, "int_key") == 0);
    assert(int_entry.type == CONFIN_ANNOTYPE_INT);
    assert(int_entry.size == sizeof(int));
    assert(CF_UNREF_ENTRYVAL(int_entry.value, int) == 42);

    cffreecfgentry(&int_entry);
    assert(int_entry.value == NULL);
}

// Function to cleanup test files
void cleanup_test_files() {
    const char *files[] = {
        "config_test.bin",
        "config_test_empty.bin",
        "empty_file.bin"
    };

    for (size_t i = 0; i < sizeof(files) / sizeof(files[0]); ++i) {
        if (remove(files[i]) != 0) {
            perror("Error deleting file");
        }
    }
}