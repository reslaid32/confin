/**
 * @file cfio.h
 * @brief Functions and macros for reading and writing configuration files in Confin format.
 * 
 * This file provides macros and function declarations for writing configuration entries
 * to files and reading configuration files in the Confin format. It includes functions
 * for handling both individual configuration entries and complete configuration file
 * structures.
 */

#ifndef _CONFIN_IO_H
#define _CONFIN_IO_H

#include "cftype.h" // confin/cftype.h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Macro to write the configuration to a file.
 * 
 * This macro calls the `confin_write_config` function to write the given
 * configuration entries to the specified file.
 * 
 * @param filename The name of the file to write the configuration to.
 * @param entries Array of configuration entries to write.
 * @param entrycount Number of configuration entries.
 */
#define cfwritecfg(filename, entries, entrycount) \
    confin_write_config(filename, entries, entrycount)

/**
 * @brief Writes the configuration to a file.
 * 
 * This function writes an array of configuration entries to a specified file.
 * 
 * @param filename The name of the file to write the configuration to.
 * @param entries Array of configuration entries to write.
 * @param entrycount Number of configuration entries.
 */
void confin_write_config(const char *filename, cfentry_t *entries, uint64_t entrycount);

/**
 * @brief Macro to write the configuration to a file using a configuration file structure.
 * 
 * This macro calls the `confin_write_config_file` function to write the
 * given configuration file structure to the specified file.
 * 
 * @param filename The name of the file to write the configuration to.
 * @param cffile Pointer to the configuration file structure (`cffile_t`) to write.
 */
#define cfwritecfgfile(filename, cffile) \
    confin_write_config_file(filename, cffile)

/**
 * @brief Writes the configuration file structure to a binary file.
 * 
 * This function writes the configuration file structure to a specified file.
 * 
 * @param filename The name of the file to write the configuration to.
 * @param file Pointer to the configuration file structure (`cffile_t`) to write.
 */
void confin_write_config_file(const char *filename, cffile_t *file);

/**
 * @brief Macro to read the configuration from a file.
 * 
 * This macro calls the `confin_read_config` function to read the configuration
 * from the specified file.
 * 
 * @param filename The name of the file to read the configuration from.
 * @return Pointer to the configuration file structure, or NULL on failure.
 */
#define cfreadcfg(filename) \
    confin_read_config(filename)

/**
 * @brief Reads the configuration from a file.
 * 
 * This function reads the configuration from the specified file and returns
 * a pointer to the configuration file structure.
 * 
 * @param filename The name of the file to read the configuration from.
 * @return Pointer to the configuration file structure, or NULL on failure.
 */
cffile_t *confin_read_config(const char *filename);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _CONFIN_IO_H
