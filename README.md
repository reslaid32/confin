# Configuration File Library

> **The repository is under development**

This library provides a set of functions and structures to handle configuration files in a binary format. It includes functionality for creating, writing, reading, and managing configuration entries and files.

## Macros

### __CONFIN_STRUCT_MAGIC_NUMBER
Defines the magic number used to verify the integrity of the configuration file.
> *Location*: [cfdef.h](./confin/cfdef.h)

### __CONFIN_VERSION
Specifies the version of the configuration file format.
> *Location*: [cfdef.h](./confin/cfdef.h)

### _CF_VER
Allias for [`__CONFIN_VERSION`](#__confin_version)
Specifies the version of the configuration file format.
> *Location*: [cfdef.h](./confin/cfdef.h)

### __CONFIN_MAJOR_VERSION
Gets the confin major version
> *Location*: [cfdef.h](./confin/cfdef.h)

### __CONFIN_MINOR_VERSION
Gets the confin minor version
> *Location*: [cfdef.h](./confin/cfdef.h)

### __CONFIN_GET_MAJOR_VERSION
Gets the major version using bitwise operations (MAJOR.MINOR)
Parameters:
- **_Ver**: Whole version ([`_CF_VER`](#_cf_ver) format)
> *Location*: [cfdef.h](./confin/cfdef.h)

### __CONFIN_GET_MINOR_VERSION
Gets the minor version using bitwise operations (MAJOR.MINOR)
Parameters:
- **_Ver**: Whole version ([`_CF_VER`](#_cf_ver) format)
> *Location*: [cfdef.h](./confin/cfdef.h)

### __CONFIN_STRUCT_MAX_KEYLEN
Defines the maximum length of a key in a configuration entry.
> *Location*: [cfdef.h](./confin/cfdef.h)

### __CONFIN_REF_ENTRY_VALUE(Value, Type)
Macro to reference a value pointer of a given type.
Parameters:
- **Value**: Pointer to the value to be referenced.
- **Type**: Type of the value to cast the referenced pointer to.
> *Location*: [cfdef.h](./confin/cfdef.h)

### CF_REF_ENTRYVAL(V, T)
Alias for [`__CONFIN_REF_ENTRY_VALUE`](#__confin_ref_entry_valuevalue-type).
- **V**: Pointer to the value to be referenced.
- **T**: Type of the value to cast the referenced pointer to.
> *Location*: [cfdef.h](./confin/cfdef.h)

### __CONFIN_UNREF_ENTRY_VALUE(Value, Type)
Macro to dereference a value pointer of a given type.
- **Value**: Pointer to the value to be dereferenced.
- **Type**: Type of the value to cast the dereferenced pointer to.
> *Location*: [cfdef.h](./confin/cfdef.h)

### CF_UNREF_ENTRYVAL(V, T)
Alias for [`__CONFIN_UNREF_ENTRY_VALUE`](#__confin_unref_entry_valuevalue-type).
- **V**: Pointer to the value to be dereferenced.
- **T**: Type of the value to cast the dereferenced pointer to.
> *Location*: [cfdef.h](./confin/cfdef.h)

## Structures & Enums

### cfannotype_t [enum __e_confin_annotype]
An enumeration defining the annotation types for configuration entries. Includes:
- `CONFIN_ANNOTYPE_INT`: Integer type
- `CONFIN_ANNOTYPE_FLOAT`: Float type
- `CONFIN_ANNOTYPE_STRING`: String type
- `CONFIN_ANNOTYPE_STRUCT`: Struct type

### cfheader_t [struct __s_confin_header]
Structure representing the header of a configuration file, containing:
- `magic`: Magic number for file integrity verification.
- `version`: Version of the configuration file format.
- `entrycount`: Number of entries in the configuration file.

### cfentry_t [struct __s_confin_entry]
Structure representing a single entry in a configuration file, including:
- `key`: Key associated with the entry.
- `type`: Annotation type of the entry.
- `size`: Size of the value.
- `value`: Pointer to the entry value.

### cffile_t [struct __s_confin_file]
Overall structure representing a complete configuration file, containing:
- `header`: Header information of the configuration file.
- `entries[]`: Array of configuration entries.

## Functions

### confin_write_config
Writes a set of configuration entries to a specified file.
> *Reduction*: `cfwritecfg`
> *Location*: [cfio.h](./confin/cfio.h)

### confin_write_config_file
Writes a set of configuration entries to a specified file.
The `__s_confin_file` structure is used.
> *Reduction*: `cfwritecfgfile`
> *Location*: [cfio.h](./confin/cfio.h)

### confin_read_config
Reads configuration entries from a specified file into a structure.
> *Reduction*: `cfreadcfg`
> *Location*: [cfio.h](./confin/cfio.h)

### confin_create_config_entry
Creates a configuration entry with the specified key, annotation type, value, and size.
> *Reduction*: `cfcreatecfgentry`
> *Location*: [cfutils.h](./confin/cfutils.h)

### confin_free_config_entry
Frees the memory allocated for a configuration entry.
> *Reduction*: `cffreecfgentry`
> *Location*: [cfutils.h](./confin/cfutils.h)

### confin_display_config_entry
Displays the key, type, size, and value of a configuration entry.
> *Reduction*: `cfdisplaycfgentry`
> *Location*: [cfutils.h](./confin/cfutils.h)

### confin_free_config_file
Frees the memory allocated for a configuration file structure after use.
> *Reduction*: `cffreecfgfile`
> *Location*: [cfutils.h](./confin/cfutils.h)

### confin_validate_file
Function to validate if a file conforms to the confin format
> *Reduction*: `cfvalidatefile`
> *Location*: [cffmt.h](./confin/cffmt.h)

### confin_validate_file
Scan and write to string all information in a confin format file
> *Reduction*: `cfscanfile`
> *Location*: [cffmt.h](./confin/cffmt.h)

## License
This library is licensed under the MIT License. See [LICENSE](./LICENSE) for more details.
