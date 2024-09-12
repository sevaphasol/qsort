#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "colors.h"

void color_print(const char *color_code, const char *str, ...)
{
	va_list list;
    va_start(list, str);

	set_color(color_code);

    vprintf(str, list);

	reset_color();

    va_end(list);
}

void set_color(const char *color_code)
{
	printf("%s", color_code);
}

void reset_color()
{
	printf(WHITE_CODE);
}

void color_arr_print(int* arr, int size, int middle_index, int left_index, int right_index)
{
    for (int i = 0; i < size; i++)
    {
        if (i == middle_index)
        {
            if (i == left_index || i == right_index)
            {
                purple_print("%d", arr[i]);
            }
            else
            {
                yellow_print("%d", arr[i]);
            }
            printf(" ");
        }
        else if (i == left_index || i == right_index)
        {
            green_print("%d", arr[i]);
            printf(" ");
        }
        else if (i < middle_index)
        {
            blue_print("%d", arr[i]);
            printf(" ");
        }
        else if (i > middle_index)
        {
            red_print("%d", arr[i]);
            printf(" ");
        }
    }

    printf("\n");
}
