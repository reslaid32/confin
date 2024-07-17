#ifndef _CONFIN_DEFINE_H
#define _CONFIN_DEFINE_H

// Magic number for verifying the integrity of the configuration file
#define __CONFIN_STRUCT_MAGIC_NUMBER    0xDEADBEEF

// Version of the configuration file format
#define __CONFIN_STRUCT_VERSION         1

// Version of the configuration file format [Allias]
#define CF_STRUCT_VER   __CONFIN_STRUCT_VERSION

// Maximum length of a key in the configuration entry
#define __CONFIN_STRUCT_MAX_KEYLEN      64

#define __CONFIN_UNREF_ENTRY_VALUE(Value, Type) *(*Type)Value
// Macro to dereference a value pointer of a given type.
// Parameters:
// - Value: Pointer to the value to be dereferenced.
// - Type: Type of the value to cast the dereferenced pointer to.

#define CF_UNREF_ENTRYVAL(V, T) __CONFIN_UNREF_ENTRY_VALUE(V,T)
// Macro alias for __CONFIN_UNREF_ENTRY_VALUE.
// Parameters:
// - V: Pointer to the value to be dereferenced.
// - T: Type of the value to cast the dereferenced pointer to.

#endif // _CONFIN_DEFINE_H