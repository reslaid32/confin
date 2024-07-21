#ifndef _CONFIN_FORMAT_H
#define _CONFIN_FORMAT_H

#ifndef __cplusplus
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Macro to validate if a file conforms to the confin format
#define cfvalidatefile(filename) confin_validate_file(filename)

// Function to validate if a file conforms to the confin format
// @param filename: The name of the file to validate
// @return true if the file format is valid, false otherwise
bool confin_validate_file(const char *filename);

// Macro to scan and write all information from a Confin format file to a string
#define cfscanfile(filename, outputstr, outpusz) confin_scan_file(filename, outputstr, outpusz)

// Function to scan and write all information from a Confin format file to a string
// @param filename: The name of the file to scan and display information
// @param output: The output line in which information about the file will be written
// @param output_size: Buffer size for output string
// @return true if the file format is valid and information is displayed, false otherwise
bool confin_scan_file(const char *filename, char *output, size_t output_size);

#ifdef __cplusplus
} // extern "C"
#endif

#endif