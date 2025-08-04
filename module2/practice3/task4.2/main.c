#include "queue.h"

int main()
{
    PriorityQueue my_queue;
    Init(&my_queue);

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        int data = rand() % 1000;
        int priority = rand() % MAX_PRIORITY;
        printf("Элемент добавлен: Число: %d, Приоритет: %d\n", data, priority);
        int flag1 = AddElements(&my_queue, data, priority);
        if (flag1 == 1) printf("\nПриоритет не в нужном диапазаоне!\n");
        if (flag1 == -1) printf("\nОчередь переполнена!\n");
    }
    printQueue(&my_queue);

    int first_data;
    ExtractFirstElement(&my_queue, &first_data);
    printf("\nИзвлечение первого элемента из очереди: %d", first_data);
    printQueue(&my_queue);

    int my_priority1 = 100;
    int data_with_priority1;
    int flag2 = ExtractElementPriority(&my_queue, my_priority1, &data_with_priority1);
    printf("\nИзвлечение элемента с указанным приоритетом: %d", my_priority1);
    if (!flag2) printf("\nИзвлечено число: %d", data_with_priority1);
    if (flag2) printf("\nНет числа с данным приоритетом");
    printQueue(&my_queue);

    int my_priority2 = 200;
    int data_with_priority2;
    int flag3 = ExtractElementHigherPriority(&my_queue, my_priority2, &data_with_priority2);
    printf("\nИзвлечение элемента с приоритетом не ниже: %d", my_priority2);
    if (!flag3) printf("\nИзвлечено число: %d", data_with_priority2);
    if (flag3) printf("\nНет числа с данным приоритетом");
    printQueue(&my_queue);
    
    return 0;
}