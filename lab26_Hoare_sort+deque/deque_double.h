#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    double *buff;
    int size;
    int head;
    int tail;
    int cap;
}dq_double_dyn_mass;

void dq_init(dq_double_dyn_mass *dq);
void dq_destroy(dq_double_dyn_mass *dq);
int dq_size(dq_double_dyn_mass *dq);
bool dq_is_empty(dq_double_dyn_mass *dq);
bool dq_push_back(dq_double_dyn_mass *dq, double val);
bool dq_push_front(dq_double_dyn_mass *dq, double val);
double dq_first(dq_double_dyn_mass *dq);
double dq_last(dq_double_dyn_mass *dq);
double dq_pop_back(dq_double_dyn_mass *dq);
double dq_pop_front(dq_double_dyn_mass *dq);