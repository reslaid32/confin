#ifndef _CONFIN_IO_H
#define _CONFIN_IO_H

/* [!] Implementation of functions in the confin.c file */

#include "cftype.h" // confin/cftype.h

// Macro to write the configuration to a file
#define cfwritecfg(filename, entries, entrycount) confin_write_config(filename, entries, entrycount)

// Function to write the configuration to a file
// @param filename: The name of the file to write the configuration to
// @param entries: Array of configuration entries to write
// @param entrycount: Number of configuration entries
void confin_write_config(const char *filename, cfentry_t *entries, uint64_t entrycount);

// Macro to write the configuration to a file [by cffile_t]
#define cfwritecfgfile(filename, cffile) confin_write_config_file(filename, cffile)

// Function to write the configuration file to a binary file
// @param filename: The name of the file to write the configuration to
// @param file: Pointer to the configuration file structure (`cffile_t`) to write
void confin_write_config_file(const char *filename, cffile_t *file);

// Macro to read the configuration from a file
#define cfreadcfg(filename) confin_read_config(filename)

// Function to read the configuration from a file
// @param filename: The name of the file to read the configuration from
// @return: Pointer to the configuration file structure, or NULL on failure
cffile_t *confin_read_config(const char *filename);

#endif // _CONFIN_IO_H