#ifndef QSORT_H__
#define QSORT_H__

void quick_sort(void* arr, int count, int size, int(* comp)(const void*, const void*));

int partition(char* arr, int count, int size, int(* comp)(const void*, const void*));

int find_left(char* arr, int size, int left_index, int middle_value, int(* comp)(const void *, const void*));

int find_right(char* arr, int size, int right_index, int middle_value, int(* comp)(const void *, const void*));

int swap_left_and_right(char* arr, int size, int left_index, int right_index, int middle_index);

void swap_ints(void* ptr1, void* ptr2);

#endif // QSORT_H__
