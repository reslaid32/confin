/**
 * @file cffmt.h
 * @brief Functions and macros for validating and scanning Confin format files.
 * 
 * This header file provides macros and function declarations for validating and
 * scanning files in the Confin format. It includes functions to check if a file
 * conforms to the Confin format and to scan a file and output its information as a string. 
 */

#ifndef _CONFIN_FORMAT_H
#define _CONFIN_FORMAT_H

#ifndef __cplusplus
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @def cfvalidatefile
 * @brief Macro to validate if a file conforms to the Confin format.
 * @param filename The name of the file to validate.
 * @return true if the file format is valid, false otherwise.
 */
#define cfvalidatefile(filename) confin_validate_file(filename)

/**
 * @brief Function to validate if a file conforms to the Confin format.
 * @param filename The name of the file to validate.
 * @return true if the file format is valid, false otherwise.
 */
bool confin_validate_file(const char *filename);

/**
 * @def cfscanfile
 * @brief Macro to scan and write all information from a Confin format file to a string.
 * @param filename The name of the file to scan.
 * @param outputstr The output string in which information about the file will be written.
 * @param outpusz Buffer size for output string.
 * @return true if the file format is valid and information is displayed, false otherwise.
 */
#define cfscanfile(filename, outputstr, outpusz) confin_scan_file(filename, outputstr, outpusz)

/**
 * @brief Function to scan and write all information from a Confin format file to a string.
 * @param filename The name of the file to scan.
 * @param output The output string in which information about the file will be written.
 * @param output_size Buffer size for output string.
 * @return true if the file format is valid and information is displayed, false otherwise.
 */
bool confin_scan_file(const char *filename, char *output, size_t output_size);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _CONFIN_FORMAT_H
