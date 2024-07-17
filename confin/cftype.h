#ifndef _CONFIN_TYPE_H
#define _CONFIN_TYPE_H
#include "cfstruct.h" // confin/cfstruct.h

// Enum for annotation types in configuration entries   [Type-Allias]
typedef enum   __e_confin_annotype  cfannotype_t;
// Structure for the configuration file header          [Type-Allias]
typedef struct __s_confin_header    cfheader_t;
// Structure for each configuration entry               [Type-Allias]
typedef struct __s_confin_entry     cfentry_t;
// Structure for the entire configuration file          [Type-Allias]
typedef struct __s_confin_file      cffile_t;

#endif // _CONFIN_TYPE_H