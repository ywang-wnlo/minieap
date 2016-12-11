#ifndef _MINIEAP_CONF_PARSER_H
#define _MINIEAP_CONF_PARSER_H

typedef struct _config_pair {
	char* key;
	char* value;
} CONFIG_PAIR;

/*
 * Sets the config file path
 */
void conf_parser_set_file_path(char* path);

/*
 * Parse the specific file into a dictionary (represented as an internal linked list)
 */
RESULT conf_parser_parse_now();

/*
 * Get value referenced by key. If buflen < len(dict[key]), this call will return FAILURE.
 * If there is no such key, this call will also return FAILURE.
 */
RESULT conf_parser_get_value(const char* key, char* buf, int buflen);

/*
 * Update or add entry in the dict.
 */
RESULT conf_parser_set_value(const char* key, const char* value);

/*
 * Save the dictionary to the specificed file.
 */
RESULT conf_parser_save_file();

/*
 * Free the internal dictionary.
 */
void conf_parser_free()

#endif