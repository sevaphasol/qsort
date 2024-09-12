#include <stdio.h>
#include "colors.h"
#include "qsort.h"

int main()
{
	int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    partition(arr, 0, 9);

    return 0;
}
