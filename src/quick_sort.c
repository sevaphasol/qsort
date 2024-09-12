#include <stdio.h>
#include "quick_sort.h"
#include "colors.h"

void quick_sort(void* arr, int count, int size, int(* comp)(const void *, const void*))
{
    char* arr_char_ptr = (char*) arr;

    if (count > 1)
    {
        int middle_index = partition(arr_char_ptr, count, size, comp);

        quick_sort(arr_char_ptr                          , middle_index            , size, comp);
        quick_sort(arr_char_ptr + (middle_index + 1)*size, count - middle_index - 1, size, comp);
    }
}

int partition(char* arr, int count, int size, int(* comp)(const void*, const void*))
{
    printf("\n");

    int left_index = 0;
    int right_index = count - 1;
    int middle_index = (left_index + right_index) / 2;

    int middle_value = *(arr + middle_index*size);

    color_arr_print((int*)arr, count, middle_index, left_index, right_index);

    while (left_index != right_index)
    {
        left_index = find_left(arr, size, left_index, middle_index, comp);

        // printf("%d - %d\n", arr[left_index], left_index);

        right_index = find_right(arr, size, right_index, middle_index, comp);

        // printf("%d - %d\n", arr[right_index], right_index);

        getchar();

        color_arr_print((int*)arr, count, middle_index, left_index, right_index);

        // printf("\nl - %d m - %d r - %d\n", left_index, middle_index, right_index);

        middle_index = swap_left_and_right(arr, size, left_index, right_index, middle_index);

        getchar();

        color_arr_print((int*)arr, count, middle_index, left_index, right_index);

        // printf("\nl - %d m - %d r - %d\n", left_index, middle_index, right_index);
    }
    printf("\n");

    return middle_index;
}

int find_left(char* arr, int size, int left_index, int middle_index, int(* comp)(const void *, const void*))
{
    while (comp((void*)(arr + left_index*size), (void*)(arr + middle_index*size)) < 0)
    {
        left_index++;
    }
    return left_index;
}

int find_right(char* arr, int size, int right_index, int middle_index, int(* comp)(const void *, const void*))
{
    while (comp((void*)(arr + right_index*size), (void*)(arr + middle_index*size)) > 0)
    {
        right_index--;
    }
    return right_index;
}

int swap_left_and_right(char* arr, int size, int left_index, int right_index, int middle_index)
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

        swap_ints((void*)(arr + left_index*size), (void*)(arr + right_index*size));
    }

    return middle_index;
}

void swap_ints(void* ptr1, void* ptr2)
{
    int tmp = *(int*)ptr1;
    *(int*)ptr1 = *(int*)ptr2;
    *(int*)ptr2 = tmp;
}
