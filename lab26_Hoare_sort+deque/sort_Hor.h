#include <stdio.h>
#include <stdbool.h>
#include "deque_double.h"

void sort_hoar(dq_double_dyn_mass *arr, int n);
void partition(dq_double_dyn_mass *arr, dq_double_dyn_mass *left, dq_double_dyn_mass *eq, dq_double_dyn_mass *right, double pivot);
// int partition(dq_double_dyn_mass *arr, int n, double pivot);
double find_pivot(dq_double_dyn_mass *arr, int n);
void print_dq(dq_double_dyn_mass *arr);
dq_double_dyn_mass* merge_deq(dq_double_dyn_mass *to, dq_double_dyn_mass *left, dq_double_dyn_mass *eq, dq_double_dyn_mass *right);
