/*
 * var_register.h
 *
 *  Created on: Jul 18, 2025
 *      Author: Jarvis
 */

#ifndef SF_CONTENT_SF_SHELL_VAR_REGISTER_H_
#define SF_CONTENT_SF_SHELL_VAR_REGISTER_H_

#include <stdint.h>

typedef enum {
    VAR_TYPE_INT,
    VAR_TYPE_FLOAT,
    VAR_TYPE_STRING,
    VAR_TYPE_BOOL,
	VAR_TYPE_ARRAY,
} var_type_t;

typedef struct {
    const char *name;
    void *addr;
    var_type_t type;
    // array only
    var_type_t elem_type;
    int elem_size;
    int elem_count;
} var_entry_t;

void shell_register_variable(const char *name, void *addr, var_type_t type);
void shell_register_array(const char *name, void *addr, var_type_t elem_type,
		int elem_size, int elem_count);
int shell_get_variable(const char *name, char *output, int max_len);
int shell_set_variable(const char *name, const char *value_str);
void shell_var_list(void);

// 宏注册变量
#define SHELL_VAR_REGISTER(var, type) \
    shell_register_variable(#var, &var, type)



#endif /* SF_CONTENT_SF_SHELL_VAR_REGISTER_H_ */
