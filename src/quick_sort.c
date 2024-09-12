#include <stdio.h>
#include "quick_sort.h"
#include "colors.h"

void quick_sort(int* arr, int count, int size, int(* comp)(const int*, const int*))
{
    if (count > 1)
    {
        int middle_index = partition(arr, count, size, comp);

        quick_sort(arr                   , middle_index            , size, comp);
        quick_sort(arr + middle_index + 1, count - middle_index - 1, size, comp);
    }
}

int partition(int* arr, int count, int size, int(* comp)(const int*, const int*))
{
    printf("\n");

    int left_index = 0;
    int right_index = count - 1;
    int middle_index = (left_index + right_index) / 2;

    int middle_value = *(arr + middle_index);

    color_arr_print(arr, count, middle_index, left_index, right_index);

    while (left_index != right_index)
    {
        left_index = find_left(arr, left_index, middle_value);

        // printf("%d - %d\n", arr[left_index], left_index);

        right_index = find_right(arr, right_index, middle_value);

        // printf("%d - %d\n", arr[right_index], right_index);

        getchar();

        color_arr_print(arr, count, middle_index, left_index, right_index);

        // printf("\nl - %d m - %d r - %d\n", left_index, middle_index, right_index);

        middle_index = swap_left_and_right(arr, left_index, right_index, middle_index);

        getchar();

        color_arr_print(arr, count, middle_index, left_index, right_index);

        // printf("\nl - %d m - %d r - %d\n", left_index, middle_index, right_index);
    }
    printf("\n");

    return middle_index;
}

int find_left(int* arr, int left_index, int middle_value)
{
    while (*(arr + left_index) < middle_value)
    {
        left_index++;
    }
    return left_index;
}

int find_right(int* arr, int right_index, int middle_value)
{
    while (*(arr + right_index) > middle_value)
    {
        right_index--;
    }
    return right_index;
}

int swap_left_and_right(int* arr, int left_index, int right_index, int middle_index)
{
    if (left_index != right_index)
    {
        if(left_index == middle_index)
        {
            middle_index = right_index;
        }

        else if(right_index == middle_index)
        {
            middle_index = left_index;
        }

        int tmp              = *(arr + left_index);
        *(arr + left_index)  = *(arr + right_index);
        *(arr + right_index) = tmp;
    }

    return middle_index;
}

