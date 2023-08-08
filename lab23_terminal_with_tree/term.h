#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include "Tree_OV.h"

enum State{
    WHAT_SYMBLE,
    IS_SPACE,
    IF_COMMAND,
    I_COMMAND,
    C_COMMAND,
    D_COMMAND,
    P_COMMAND,
    F_COMMAND,
    TRASH,
    OTHER,
};


int is_space(int c);
void command_list();
void Error_list(int i);
void Info_list(int i);
void print_enum_reference();
int get_int_enum(char* st);