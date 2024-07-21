/**
 * @file confin_type.h
 * @brief Type definitions for the Confin library.
 * 
 * This header file defines type aliases for the data structures and enumerations used
 * in the Confin library. It provides more convenient names for the types defined in
 * `confin_struct.h`.
 */

#ifndef _CONFIN_TYPE_H
#define _CONFIN_TYPE_H

#include "cfstruct.h" // confin/cfstruct.h

/**
 * @typedef cfannotype_t
 * @brief Type alias for annotation types in configuration entries.
 * 
 * This type alias represents the enumeration that defines the different types of
 * values that configuration entries can have. It is equivalent to `enum __e_confin_annotype`.
 */
typedef 
#ifndef __cplusplus
    enum
#endif
    __e_confin_annotype cfannotype_t;

/**
 * @typedef cfheader_t
 * @brief Type alias for the configuration file header structure.
 * 
 * This type alias represents the structure that holds metadata for a configuration file.
 * It is equivalent to `struct __s_confin_header`.
 */
typedef struct __s_confin_header cfheader_t;

/**
 * @typedef cfentry_t
 * @brief Type alias for the configuration entry structure.
 * 
 * This type alias represents a single entry in a configuration file, including its key,
 * type, size, and value. It is equivalent to `struct __s_confin_entry`.
 */
typedef struct __s_confin_entry cfentry_t;

/**
 * @typedef cffile_t
 * @brief Type alias for the configuration file structure.
 * 
 * This type alias represents the entire configuration file, including its header and
 * an array of configuration entries. It is equivalent to `struct __s_confin_file`.
 */
typedef struct __s_confin_file cffile_t;

#endif // _CONFIN_TYPE_H
