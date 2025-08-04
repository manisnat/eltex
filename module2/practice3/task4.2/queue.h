#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PRIORITY 256
#define MAX_ELEMENTS 100

typedef struct {
    int data;
    int priority;
} QueueElement;

typedef struct {
    QueueElement elements[MAX_ELEMENTS];
    int size;
} PriorityQueue;

void Init(PriorityQueue* q);
int AddElements(PriorityQueue* q, int data, int priority);
void printQueue(PriorityQueue* q);
int ExtractFirstElement(PriorityQueue* q, int* data);
int ExtractElementPriority(PriorityQueue* q, int priority, int* data);
int ExtractElementHigherPriority(PriorityQueue* q, int priority, int* data);

#endif
