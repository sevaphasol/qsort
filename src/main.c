#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "quick_sort.h"
#include "comp.h"

int main()
{
	int arr1[10] = {8, 5, 9, 2, 3, 4, 1, 0, 7, 6};
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr3[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr4[10] = {6, 9, 4, 2, 5, 8, 1, 0, 7, 3};
    int arr5[10] = {9, 4, 3, 5, 7, 8, 5, 1, 6, 2}; // doesn't work with repeated elemets
    char arr6[10] = {'b', 'a', 'd', 'c', 'f', 'e', 'h', 'g', 'j', 'i'};
    quick_sort(arr6, 10, sizeof(char), &char_compare);
    // qsort(arr1, 10, 4, &int_compare);

    for (int i = 0; i < 10; i++)
    {

        printf("%c ", arr6[i]);
    }
    printf("\n");

    return 0;
}
