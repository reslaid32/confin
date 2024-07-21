#ifndef _CONFIN_DEFINE_H
#define _CONFIN_DEFINE_H

// Magic number for verifying the integrity of the configuration file
#define __CONFIN_STRUCT_MAGIC_NUMBER    0xDEADBEEF // 4 bytes (32-bits)

// Version of the configuration file format
#define __CONFIN_MAJOR_VERSION 1
#define __CONFIN_MINOR_VERSION 1
#define __CONFIN_VERSION ((__CONFIN_MAJOR_VERSION << 16) | __CONFIN_MINOR_VERSION)
#define __CONFIN_GET_MAJOR_VERSION(_Ver) ((_Ver >> 16) & 0xFFFF)
#define __CONFIN_GET_MINOR_VERSION(_Ver) (_Ver & 0xFFFF)

// Version of the configuration file format [Allias]
#define _CF_VER                         __CONFIN_VERSION

// Maximum length of a key in the configuration entry
#define __CONFIN_STRUCT_MAX_KEYLEN      64

// Macro to reference a value pointer of a given type.
// Parameters:
// - Value: Pointer to the value to be referenced.
// - Type: Type of the value to cast the referenced pointer to.
#define __CONFIN_REF_ENTRY_VALUE(Value, Type) (Type*)Value

// Macro alias for __CONFIN_REF_ENTRY_VALUE.
// Parameters:
// - V: Pointer to the value to be referenced.
// - T: Type of the value to cast the referenced pointer to.
#define CF_REF_ENTRYVAL(V, T) __CONFIN_REF_ENTRY_VALUE(V,T)

// Macro to dereference a value pointer of a given type.
// Parameters:
// - Value: Pointer to the value to be dereferenced.
// - Type: Type of the value to cast the dereferenced pointer to.
#define __CONFIN_UNREF_ENTRY_VALUE(Value, Type) *__CONFIN_REF_ENTRY_VALUE(Value, Type)

// Macro alias for __CONFIN_UNREF_ENTRY_VALUE.
// Parameters:
// - V: Pointer to the value to be dereferenced.
// - T: Type of the value to cast the dereferenced pointer to.
#define CF_UNREF_ENTRYVAL(V, T) __CONFIN_UNREF_ENTRY_VALUE(V,T)

#endif // _CONFIN_DEFINE_H