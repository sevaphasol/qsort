#include <stdio.h>
#include "colors.h"
#include "quick_sort.h"

int main()
{
	int arr[10] = {8, 5, 9, 2, 3, 4, 1, 0, 7, 6};
    quick_sort(arr, 0, 9);
    return 0;
}
