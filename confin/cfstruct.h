#ifndef _CONFIN_STRUCT_H
#define _CONFIN_STRUCT_H

#include <stdint.h>

#include "cfdef.h" // confin/cfdef.h

#ifndef __cplusplus
// Enum for annotation types in configuration entries
enum    __e_confin_annotype;
#endif
// Structure for the configuration file header
struct  __s_confin_header;
// Structure for each configuration entry
struct  __s_confin_entry;
// Structure for the entire configuration file
struct  __s_confin_file;

// Enum for annotation types in configuration entries
enum __e_confin_annotype {
    CONFIN_ANNOTYPE_INT,    // Integer type
    CONFIN_ANNOTYPE_FLOAT,  // Float type
    CONFIN_ANNOTYPE_STRING,  // String type
    CONFIN_ANNOTYPE_STRUCT  // Structure type
};

// Structure for the configuration file header
struct __s_confin_header {
    uint32_t magic;         // Magic number to identify the configuration file
    uint32_t version;       // Version of the configuration file format
    uint64_t entrycount;    // Number of entries in the configuration file
};

// Structure for the configuration file header
struct __s_confin_entry {
    char key[__CONFIN_STRUCT_MAX_KEYLEN]; // Key of the configuration entry
    /* [Annotation] Type of the value (
        int: CONFIN_ANNOTYPE_INT,
        float: CONFIN_ANNOTYPE_FLOAT,
        string: CONFIN_ANNOTYPE_STRING,
        struct: CONFIN_ANNOTYPE_STRUCT
    )*/
    enum __e_confin_annotype type;
    uint64_t size;                        // Size of the value
    void *value;                          // Pointer to the value
};

#ifdef _MSC_VER
    #pragma warning(push)
    #pragma warning(disable: 4200)
#endif

// Structure for the entire configuration file
struct __s_confin_file {
    struct __s_confin_header header; // Header of the configuration file
    struct __s_confin_entry entries[]; // Array of configuration entries
};

#ifdef _MSC_VER
    #pragma warning(pop)
#endif

#endif // _CONFIN_STRUCT_H