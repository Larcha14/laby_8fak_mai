#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "vectorCerclBuf.h"
#define START_SIZE 50

typedef struct data{
    int m, n;
    int count;
    int k_cip;
    ddl_vector_Cercle CIP; //с какого индекса начинаются каждая строчка, типо того
    ddl_vector_Cercle PI; // столбцы, в которых расположены элементы
    ddl_vector_Cercle YE; // value
}data;

// void create_data(data mas, int m, int n);
data create_data(int m, int n);
void mat_print(data mas);
void vec_print(data mas);
void function(data mas);