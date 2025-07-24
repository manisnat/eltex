#ifndef CHMOD_H
#define CHMOD_H

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int valid_letters(const char* letters);
int letters_in_octal(char* letters);
int octal_in_letters(int octal, char* letters);
void print_binary(int octal);
int stat_file(char* name, int* octal);
int edit_right(char *buffer, int* octal);

#endif