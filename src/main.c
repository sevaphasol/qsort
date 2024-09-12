#include <stdio.h>
#include "colors.h"
#include "quick_sort.h"
#include "comp.h"

int main()
{
	int arr[10] = {8, 5, 9, 2, 3, 4, 1, 0, 7, 6};
    quick_sort(arr, 10, 4, &comp);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
