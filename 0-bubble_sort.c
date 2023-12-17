#include "sort.h"
/**
 * bubble_sort - This function impliment Bubble sorting
 * algorithm
 * array: The array to be sorted
 * size: the size of the array
 * Return: void
 */
 void bubble_sort(int *array, size_t size)
 {
    size_t i, j, flag, temp;

    for(i = 0; i < size - 1; i++)
    {
        flag = 0;

        for(j = 0; j < size - 1 - i; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
            print_array(array, size);
        }
        if(flag == 0)
        {
            break;
        }
    }
 }