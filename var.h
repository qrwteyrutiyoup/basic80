#ifndef _VAR_H
#define _VAR_H

#include "basic.h"
#include "error.h"
#include "math.h"
#include <stdio.h>
#include <string.h>

#define STRING_SPACE_SIZE 10000

// Array used to store all string vars.
char string_space[STRING_SPACE_SIZE];
long string_space_pos;


// A var must be identified by its first two letters.
float var[26][26+17];
char *str_var[26][26+17];
void clear_vars();
float get_var(char*);
float *set_var(char*,float);
int test_attribution(char*);
int set_str_var(char*, char*);
char *get_str_var(char*);
void print_str_var(char*);
float *exec_attribution(char*);
float *get_var_pointer(char*);

#endif
