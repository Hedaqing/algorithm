//
// Created by hedaqing on 18-7-15.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../header/mySort.h"
#include "../header/myLib.h"

void sortMain() {

    int len = 100;
    int rangeL = 0;
    int rangeR = 1000;
    int * arr = (int*)malloc(sizeof(int)*len);


/** generate random array, print it **/

    generateRandomArray(len, rangeL, rangeR, arr);
    printf("original array:\t");
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");


/** selection sort, print it **/

    int * arr_selectionSort = (int*)malloc(sizeof(int)*len);
    copyIntArray(len, arr, arr_selectionSort);
    selectionSort(len, arr_selectionSort);
    printf("selection sort:\t");
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr_selectionSort[i]);
    }
    printf("\n");


/** insertion sort, print it **/

    int * arr_insertionSort = (int*)malloc(sizeof(int)*len);
    copyIntArray(len, arr, arr_insertionSort);
    insertionSort(len, arr_insertionSort);
    printf("insertion sort:\t");
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr_insertionSort[i]);
    }
    printf("\n");


/** bubble sort, print it **/

    int * arr_bubbleSort = (int*)malloc(sizeof(int)*len);
    copyIntArray(len, arr, arr_bubbleSort);
    bubbleSort(len, arr_bubbleSort);
    printf("bubble sort:\t");
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr_bubbleSort[i]);
    }
    printf("\n");


/** merge sort, print it **/

    int * arr_mergeSort = (int*)malloc(sizeof(int)*len);
    copyIntArray(len, arr, arr_mergeSort);
    mergeSort(len, arr_mergeSort);
    printf("merge sort:\t\t");
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr_mergeSort[i]);
    }
    printf("\n");


/** quick sort, print it **/

    int * arr_quickSort = (int*)malloc(sizeof(int)*len);
    copyIntArray(len, arr, arr_quickSort);
    quickSort(len, arr_quickSort);
    printf("quick sort:\t\t");
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr_quickSort[i]);
    }
    printf("\n");
}


/**
 * selection sort
 * n^2
 * @param len
 * @param arr
 */
void selectionSort(int len, int * arr) {
    for (int i = 0; i < len; ++i) {
        int min_index = i;
        int min = arr[i];
        for (int j = i+1; j < len; ++j) {
            if (arr[j] < min) {
                min_index = j;
                min = arr[j];
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[min_index] = temp;
    }
}


/**
 * insertion sort
 * n^2
 * 基本有序的情况下效率会非常高(nearly ordered array)
 * @param len
 * @param arr int *
 */
void insertionSort(int len, int * arr) {

    for (int i=1; i< len; ++i) {
        int current = arr[i];
        int index = i;
        for (int j=i-1; j >= 0 && arr[j] > current; --j) {
            arr[j+1] = arr[j];
            index = j;
        }
        arr[index] = current;
    }
}


/**
 * 希尔排序算法，由插入排序算法衍生出来
 * @param len
 * @param arr
 */
void shellSort(int len, int * arr){

}


/**
 * bubble sort
 * n^2
 * @param len
 * @param arr
 */
void bubbleSort(int len, int * arr) {
    bool flag = true;
    while (flag) {
        bool isSwapped = false;
        for (int i = 0; i < len-1; ++i) {
            if (arr[i] > arr[i+1]) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                isSwapped = true;
            }
        }
        flag = isSwapped;
    }
}


/**
 * quick sort
 * @param arr
 * @param left
 * @param right
 */
void __quickSort(int * arr, int left, int right){

    if (left >= right){
        return;
    }

    int leftPointer = left;
    int rightPointer = right;
    int keyValue = arr[leftPointer];

    while (rightPointer > leftPointer){
        while (rightPointer > leftPointer && arr[rightPointer] >= keyValue){
            rightPointer --;
        }
        arr[leftPointer] = arr[rightPointer];

        while (rightPointer > leftPointer && arr[leftPointer] <= keyValue) {
            leftPointer ++;
        }
        arr[rightPointer] = arr[leftPointer];
    }
    arr[leftPointer] = keyValue;

    __quickSort(arr, left, leftPointer);
    __quickSort(arr, leftPointer+1, right);
}


/**
 * quick sort,对冒泡排序的一种改进
 * 整个排序过程可以递归进行
 * n*log(n)
 * @param len
 * @param arr
 */
void quickSort (int len, int * arr) {

    if (len <=1){
        return;
    }
    printf("in quick sort\n");
    __quickSort(arr, 0, len-1);
}


/**
 * merge sort
 * @param arr
 * @param l
 * @param mid
 * @param r
 */
void __merge(int * arr, int l, int mid, int r){
    int len = r - l + 1;
    int * aux = (int*)malloc(sizeof(int)*(len)); //辅助空间

    for (int i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }

    int leftPointer = 0;
    int rightPointer = mid+1-l;
    int kPointer = l;

    for (; kPointer <= r ; kPointer++) {
        if (leftPointer > mid-l){
            arr[kPointer] = aux[rightPointer];
            rightPointer ++;
            continue;
        }

        if (rightPointer > r-l) {
            arr[kPointer] = aux[leftPointer];
            leftPointer ++;
            continue;
        }
        if (aux[leftPointer] < aux[rightPointer]){
            arr[kPointer] = aux[leftPointer];
            leftPointer ++;
            continue;
        }
        if (aux[leftPointer] > aux[rightPointer]){
            arr[kPointer] = aux[rightPointer];
            rightPointer ++;
            continue;
        }
        if (aux[leftPointer] == aux[rightPointer]){
            arr[kPointer] = aux[leftPointer];
            arr[++kPointer] = aux[rightPointer];
            leftPointer ++;
            rightPointer ++;
            continue;
        }
    }

}


/**
 * merge sort
 * @param arr
 * @param l
 * @param r
 */
void __mergeSort(int * arr, int l, int r) {
    if (l >= r){
        return;
    }

    int mid = (l + r)/2; // TODO

    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if (arr[mid] > arr[mid+1])
        __merge(arr, l, mid, r);
}


/**
 * merge sort
 * n*log(n)
 * @param len
 * @param arr
 */
void mergeSort(int len, int * arr) {
    int l = 0;
    int r = len - 1;
    __mergeSort(arr, l, r);
}


/**
 * binary search
 * @param arr
 * @param left
 * @param right
 * @param key
 */
void __binarySearch(int * arr, int left, int right, int key){
    int len = right - left + 1;

    if (len < 1)
        return;
    if (len == 1){
        if (key == arr[left])
            printf("got key: %d\n", key);
        return;
    }

    if (key > arr[left + len/2])
        __binarySearch(arr, left+len/2+1, right, key);
    else if (key < arr[left+ len/2])
        __binarySearch(arr, left, left+ len/2-1, key);
    else
        printf("got key: %d\n", key);
}


/**
 * binary search
 * @param arr
 * @param len
 * @param key
 */
void binarySearch(int * arr, int len, int key) {

    if (len < 1){
        return;
    }
    if (len == 1){
        if (key == arr[0])
            printf("got key: %d\n", key);
        return;
    }

    if (key > arr[len/2]){
        __binarySearch(arr, len/2+1, len-1, key);
    }
    else if (key< arr[len/2]){
        __binarySearch(arr, 0, len/2-1, key);
    } else
        printf("got key: %d\n", key);
}

