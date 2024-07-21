/**
 * @file cfdef.h
 * @brief Defines and macros for the Confin configuration file library.
 * 
 * This header file contains essential definitions and macros used throughout the Confin
 * configuration file library. It includes versioning information, magic numbers, and
 * utility macros for handling configuration entries and values.
 */

#ifndef _CONFIN_DEFINE_H
#define _CONFIN_DEFINE_H

/**
 * @def __CONFIN_STRUCT_MAGIC_NUMBER
 * @brief Magic number for verifying the integrity of the configuration file.
 */
#define __CONFIN_STRUCT_MAGIC_NUMBER    0xDEADBEEF // 4 bytes (32-bits)

/**
 * @def __CONFIN_MAJOR_VERSION
 * @brief Major version of the configuration file format.
 */
#define __CONFIN_MAJOR_VERSION 1

/**
 * @def __CONFIN_MINOR_VERSION
 * @brief Minor version of the configuration file format.
 */
#define __CONFIN_MINOR_VERSION 1

/**
 * @def __CONFIN_VERSION
 * @brief Combined major and minor version of the configuration file format.
 */
#define __CONFIN_VERSION ((__CONFIN_MAJOR_VERSION << 16) | __CONFIN_MINOR_VERSION)

/**
 * @def __CONFIN_GET_MAJOR_VERSION
 * @brief Gets the major version from the combined version.
 * @param _Ver The combined version.
 * @return The major version.
 */
#define __CONFIN_GET_MAJOR_VERSION(_Ver) ((_Ver >> 16) & 0xFFFF)

/**
 * @def __CONFIN_GET_MINOR_VERSION
 * @brief Gets the minor version from the combined version.
 * @param _Ver The combined version.
 * @return The minor version.
 */
#define __CONFIN_GET_MINOR_VERSION(_Ver) (_Ver & 0xFFFF)

/**
 * @def _CF_VER
 * @brief Alias for the combined version of the configuration file format.
 */
#define _CF_VER __CONFIN_VERSION

/**
 * @def __CONFIN_STRUCT_MAX_KEYLEN
 * @brief Maximum length of a key in the configuration entry.
 */
#define __CONFIN_STRUCT_MAX_KEYLEN 64

/**
 * @def __CONFIN_REF_ENTRY_VALUE
 * @brief Macro to reference a value pointer of a given type.
 * @param Value Pointer to the value to be referenced.
 * @param Type Type of the value to cast the referenced pointer to.
 * @return The referenced pointer cast to the specified type.
 */
#define __CONFIN_REF_ENTRY_VALUE(Value, Type) (Type*)Value

/**
 * @def CF_REF_ENTRYVAL
 * @brief Macro alias for __CONFIN_REF_ENTRY_VALUE.
 * @param V Pointer to the value to be referenced.
 * @param T Type of the value to cast the referenced pointer to.
 * @return The referenced pointer cast to the specified type.
 */
#define CF_REF_ENTRYVAL(V, T) __CONFIN_REF_ENTRY_VALUE(V, T)

/**
 * @def __CONFIN_UNREF_ENTRY_VALUE
 * @brief Macro to dereference a value pointer of a given type.
 * @param Value Pointer to the value to be dereferenced.
 * @param Type Type of the value to cast the dereferenced pointer to.
 * @return The dereferenced value cast to the specified type.
 */
#define __CONFIN_UNREF_ENTRY_VALUE(Value, Type) *__CONFIN_REF_ENTRY_VALUE(Value, Type)

/**
 * @def CF_UNREF_ENTRYVAL
 * @brief Macro alias for __CONFIN_UNREF_ENTRY_VALUE.
 * @param V Pointer to the value to be dereferenced.
 * @param T Type of the value to cast the dereferenced pointer to.
 * @return The dereferenced value cast to the specified type.
 */
#define CF_UNREF_ENTRYVAL(V, T) __CONFIN_UNREF_ENTRY_VALUE(V, T)

#endif // _CONFIN_DEFINE_H
