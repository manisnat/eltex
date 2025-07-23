#ifndef SIMPLE_CALCULATOR_H
#define SIMPLE_CALCULATOR_H

double add(int num_args, ...);
double sub(int num_args, ...);
double mult(int num_args, ...);
int div(double *result, int num_args, ...);
void print_nums(int count, double* nums);

#endif