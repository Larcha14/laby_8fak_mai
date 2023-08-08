#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef DATA_H
#define DATA_H

typedef struct data{
    char key[7]; 
    char str[100];
} data;

int line_counter(char* arg);
void text_print(data origin[], int size);
void merge(FILE* lines, FILE* keys, data arr[]);
void reverse_data(FILE* lines, FILE* keys, data arr[], int size);
void random_data(FILE* lines, FILE* keys, data arr[], int size);

#endif    