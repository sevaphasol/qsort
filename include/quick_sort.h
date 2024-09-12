#ifndef QSORT_H__
#define QSORT_H__

void quick_sort(int* arr, int count, int size, int(* comp)(const int*, const int*));

int partition(int* arr, int count, int size, int(* comp)(const int*, const int*));

int find_left(int* arr, int left_index, int middle_value);

int find_right(int* arr, int right_index, int middle_value);

int swap_left_and_right(int* arr, int left_index, int right_index, int middle_index);

#endif // QSORT_H__
