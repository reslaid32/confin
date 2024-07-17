# Configuration File Library

This library provides a set of functions and structures to handle configuration files in a binary format. It includes functionality for creating, writing, reading, and managing configuration entries and files.

## Macros

### __CONFIN_STRUCT_MAGIC_NUMBER
Defines the magic number used to verify the integrity of the configuration file.

### __CONFIN_STRUCT_VERSION
Specifies the version of the configuration file format.

### __CONFIN_STRUCT_MAX_KEYLEN
Defines the maximum length of a key in a configuration entry.

## Structures & Enums

### cfannotype_t [enum __e_confin_annotype]
An enumeration defining the annotation types for configuration entries. Includes:
- CONFIN_ANNOTYPE_INT: Integer type
- CONFIN_ANNOTYPE_FLOAT: Float type
- CONFIN_ANNOTYPE_STRING: String type

### cfheader_t [struct __s_confin_header]
Structure representing the header of a configuration file, containing:
- `magic`: Magic number for file integrity verification.
- `version`: Version of the configuration file format.
- `entrycount`: Number of entries in the configuration file.

### cfentry_t [struct __s_confin_entry]
Structure representing a single entry in a configuration file, including:
- `key`: Key associated with the entry.
- `type`: Annotation type of the entry (integer, float, or string).
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
