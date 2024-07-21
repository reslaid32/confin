/**
 * @file confin_utils.h
 * @brief Utility functions and macros for managing Confin configuration entries and files.
 * 
 * This header file defines macros and functions for creating, displaying, and freeing
 * configuration entries and files in the Confin library. It provides utility functions
 * to simplify the management of configuration data.
 */

#ifndef _CONFIN_UTILS_H
#define _CONFIN_UTILS_H

#include "cftype.h" // confin/cftype.h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Macro to create a configuration entry.
 * 
 * This macro calls the `confin_create_config_entry` function to create a new
 * configuration entry with the specified key, type, value, and size.
 * 
 * @param key The key for the configuration entry.
 * @param annotype The type of the value (see @ref cfannotype_t).
 * @param value The value to be stored in the configuration entry.
 * @param size The size of the value.
 * @return The created configuration entry.
 */
#define cfcreatecfgentry(key, annotype, value, size) \
    confin_create_config_entry(key, annotype, value, size)

/**
 * @brief Creates a configuration entry.
 * 
 * This function creates a new configuration entry with the specified key, type,
 * value, and size. It allocates and initializes the configuration entry structure.
 * 
 * @param key The key for the configuration entry.
 * @param type The type of the value (see @ref cfannotype_t).
 * @param value The value to be stored in the configuration entry.
 * @param size The size of the value.
 * @return The created configuration entry.
 */
cfentry_t confin_create_config_entry(const char *key, cfannotype_t type, const void *value, uint64_t size);

/**
 * @brief Macro to free a configuration entry.
 * 
 * This macro calls the `confin_free_config_entry` function to free the memory
 * allocated for a configuration entry.
 * 
 * @param entry Pointer to the configuration entry to be freed.
 */
#define cffreecfgentry(entry) \
    confin_free_config_entry(entry)

/**
 * @brief Frees a configuration entry.
 * 
 * This function frees the memory allocated for a configuration entry.
 * 
 * @param entry Pointer to the configuration entry to be freed.
 */
void confin_free_config_entry(cfentry_t *entry);

/**
 * @brief Macro to display a configuration entry.
 * 
 * This macro calls the `confin_display_config_entry` function to display the
 * contents of a configuration entry.
 * 
 * @param entry Pointer to the configuration entry to be displayed.
 */
#define cfdisplaycfgentry(entry) \
    confin_display_config_entry(entry)

/**
 * @brief Displays a configuration entry.
 * 
 * This function displays the contents of a configuration entry, including its
 * key, type, and value.
 * 
 * @param entry Pointer to the configuration entry to be displayed.
 */
void confin_display_config_entry(const cfentry_t *entry);

/**
 * @brief Macro to free a configuration file.
 * 
 * This macro calls the `confin_free_config_file` function to free the memory
 * allocated for a configuration file.
 * 
 * @param cfg Pointer to the configuration file to be freed.
 */
#define cffreecfgfile(cfg) \
    confin_free_config_file(cfg)

/**
 * @brief Frees a configuration file.
 * 
 * This function frees the memory allocated for a configuration file, including
 * its header and entries.
 * 
 * @param config Pointer to the configuration file to be freed.
 */
void confin_free_config_file(cffile_t *config);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _CONFIN_UTILS_H
