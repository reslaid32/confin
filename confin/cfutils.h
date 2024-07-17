#ifndef _CONFIN_UTILS_H
#define _CONFIN_UTILS_H

/* [!] Implementation of functions in the confin.c file */

#include "cftype.h" // confin/cftype.h

#ifdef __cplusplus
extern "C" {
#endif

// Macro to create a configuration entry
#define cfcreatecfgentry(key, annotype, value, size) confin_create_config_entry(key, annotype, value, size)

// Function to create a configuration entry
// @param key: The key for the configuration entry
// @param type: The type of the value (int, float, string)
// @param value: The value to be stored in the configuration entry
// @param size: The size of the value
// @return: The created configuration entry
cfentry_t confin_create_config_entry(const char *key, cfannotype_t type, const void *value, uint64_t size);

// Macro to free a configuration entry
#define cffreecfgentry(entry) confin_free_config_entry(entry)

// Function to free a configuration entry
// @param entry: Pointer to the configuration entry to be freed
void confin_free_config_entry(cfentry_t *entry);

// Macro to display a configuration entry
#define cfdisplaycfgentry(entry) confin_display_config_entry(entry)

// Function to display a configuration entry
// @param entry: Pointer to the configuration entry to be displayed
void confin_display_config_entry(const cfentry_t *entry);

// Macro to free a configuration file
#define cffreecfgfile(cfg) confin_free_config_file(cfg)

// Function to free a configuration file
// @param config: Pointer to the configuration file to be freed
void confin_free_config_file(cffile_t *config);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _CONFIN_UTILS_H
