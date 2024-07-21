/**
 * @file cfstruct.h
 * @brief Definitions of data structures used in the Confin library.
 * 
 * This header file defines the data structures and enumerations used for handling
 * configuration files in the Confin library. It includes definitions for the configuration
 * file header, entries, and the entire configuration file structure.
 */

#ifndef _CONFIN_STRUCT_H
#define _CONFIN_STRUCT_H

#ifdef __cplusplus
#include <cstdint>
#else
#include <stdint.h>
#endif

#include "cfdef.h" // confin/cfdef.h

#ifndef __cplusplus
/**
 * @enum __e_confin_annotype
 * @brief Enum for annotation types in configuration entries.
 * 
 * This enumeration defines the different types of values that can be stored in
 * configuration entries.
 */
enum __e_confin_annotype;
#endif

/**
 * @struct __s_confin_header
 * @brief Structure for the configuration file header.
 * 
 * This structure represents the header of a configuration file and includes metadata
 * such as the magic number, version, and the number of entries in the file.
 */
struct __s_confin_header {
    uint32_t magic;         /**< Magic number to identify the configuration file */
    uint32_t version;       /**< Version of the configuration file format */
    uint64_t entrycount;    /**< Number of entries in the configuration file */
};

/**
 * @enum __e_confin_annotype
 * @brief Enum for annotation types in configuration entries.
 * 
 * This enumeration defines the different types of values that configuration entries
 * can have.
 */
enum __e_confin_annotype {
    CONFIN_ANNOTYPE_INT,    /**< Integer type */
    CONFIN_ANNOTYPE_FLOAT,  /**< Float type */
    CONFIN_ANNOTYPE_STRING, /**< String type */
    CONFIN_ANNOTYPE_STRUCT  /**< Structure type */
};

/**
 * @struct __s_confin_entry
 * @brief Structure for each configuration entry.
 * 
 * This structure represents a single entry in a configuration file. It includes the
 * key, type of the value, size of the value, and a pointer to the value itself.
 */
struct __s_confin_entry {
    char key[__CONFIN_STRUCT_MAX_KEYLEN]; /**< Key of the configuration entry */
    enum __e_confin_annotype type;        /**< Type of the value (see @ref __e_confin_annotype) */
    uint64_t size;                        /**< Size of the value */
    void *value;                          /**< Pointer to the value */
};

#ifdef _MSC_VER
    #pragma warning(push)
    #pragma warning(disable: 4200)
#endif

/**
 * @struct __s_confin_file
 * @brief Structure for the entire configuration file.
 * 
 * This structure represents the entire configuration file, including the header and
 * an array of configuration entries.
 */
struct __s_confin_file {
    struct __s_confin_header header; /**< Header of the configuration file */
    struct __s_confin_entry entries[]; /**< Array of configuration entries */
};

#ifdef _MSC_VER
    #pragma warning(pop)
#endif

#endif // _CONFIN_STRUCT_H
