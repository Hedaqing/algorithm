//
// Created by hedaqing on 18-7-15.
//

#ifndef ALGORITHM_MYSORT_H
#define ALGORITHM_MYSORT_H

#endif //ALGORITHM_MYSORT_H

/**
 * selection sort
 * n^2
 * @param len
 * @param arr
 */
void selectionSort(int len, int * arr);

/**
 * insertion sort
 * n^2
 * 基本有序的情况下效率会非常高(nearly ordered array)
 * @param len
 * @param arr int *
 */
void insertionSort(int len, int * arr);

/**
 * 希尔排序算法，由插入排序算法衍生出来
 * @param len
 * @param arr
 */
void shellSort(int len, int * arr);

/**
 * bubble sort
 * n^2
 * @param len
 * @param arr
 */
void bubbleSort(int len, int * arr);

/**
 * quick sort,对冒泡排序的一种改进
 * 整个排序过程可以递归进行
 * n*log(n)
 * @param len
 * @param arr
 */
void quickSort (int len, int * arr);

/**
 * merge sort
 * n*log(n)
 * @param len
 * @param arr
 */
void mergeSort(int len, int * arr);

/**
 * binary search
 * @param arr
 * @param len
 * @param key
 */
void binarySearch(int * arr, int len, int key);

void sortMain();