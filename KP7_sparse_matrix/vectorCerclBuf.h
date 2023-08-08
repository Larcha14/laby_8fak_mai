#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define k 2
#define MIN_CAP 30

typedef struct{
    int *buff; //динамический буфер
    int cap; //capacity сколько ячеек мы выделяем для зранения
    int size;
    int head;
    int tail;

} ddl_vector_Cercle;

void init(ddl_vector_Cercle *v);
void destroy(ddl_vector_Cercle *v);
bool push_back(ddl_vector_Cercle *v, int val);
bool push_front(ddl_vector_Cercle *v,int val);
int pop_back(ddl_vector_Cercle *v);
int pop_front(ddl_vector_Cercle *v);
bool is_empty(ddl_vector_Cercle *v);
int get_size(ddl_vector_Cercle *v);
bool set_size(ddl_vector_Cercle *v, int new_size);
int get_el(ddl_vector_Cercle *v, int idx); //обращение по индексу
void set_el(ddl_vector_Cercle *v, int idx, int val);

