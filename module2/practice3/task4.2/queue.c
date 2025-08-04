#include "queue.h"

void Init(PriorityQueue* q)
{
    q->size = 0;
}

int AddElements(PriorityQueue* q, int data, int priority)
{
    if (q->size >= MAX_ELEMENTS) return -1;
    if (priority < 0 || priority >= MAX_PRIORITY) return 1;

    q->elements[q->size].data = data;
    q->elements[q->size].priority = priority;
    q->size++;

    return 0;
}

void printQueue(PriorityQueue* q)
{
    if (q->size == 0) printf("\nОчередь пуста!\n");

    printf("\nОчередь (Количество элементов %d):\n", q->size);
    for (int i = 0; i < q->size; i++)
    {
        printf("Число: %d, Приоритет: %d\n", q->elements[i].data, q->elements[i].priority);
    }
}

int ExtractFirstElement(PriorityQueue* q, int* data)
{
    if (q->size == 0) return -1;

    *data = q->elements[0].data;
    for (int i = 0; i < q->size - 1; i++)
    {
        q->elements[i] = q->elements[i+1];
    }
    q->size--;

    return 0;
} 

int ExtractElementPriority(PriorityQueue* q, int priority, int* data)
{
    if (q->size == 0) return -1;

    bool flag = 0;
    for (int i = 0; i < q->size; i++)
    {
        if (q->elements[i].priority == priority) 
        {
            *data = q->elements[i].data;
            flag = 1;
        }
        if (flag)
        {
            for (int j = i; j < q->size - 1; j++)
            {
                q->elements[j] = q->elements[j+1];
            }
            q->size--;
            return 0;
        }
    }

    return 1;
} 

int ExtractElementHigherPriority(PriorityQueue* q, int priority, int* data)
{
    if (q->size == 0) return -1;

    bool flag = 0;
    for (int i = 0; i < q->size; i++)
    {
        if (q->elements[i].priority >= priority) 
        {
            *data = q->elements[i].data;
            flag = 1;
        }
        if (flag)
        {
            for (int j = i; j < q->size - 1; j++)
            {
                q->elements[j] = q->elements[j+1];
            }
            q->size--;
            return 0;
        }
    }

    return 1;
} 
