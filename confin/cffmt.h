#ifndef _CONFIN_FORMAT_H
#define _CONFIN_FORMAT_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Macro to validate if a file conforms to the confin format
#define cfvalidatefile(filename) confin_validate_file(filename)

// Function to validate if a file conforms to the confin format
// @param filename: The name of the file to validate
// @return true if the file format is valid, false otherwise
bool confin_validate_file(const char *filename);

#ifdef __cplusplus
} // extern "C"
#endif

#endif