//
// Created by hedaqing on 18-7-15.
//

#include <stdlib.h>
#include "../header/myLib.h"
#include <time.h>

/**
 * generate random int list
 * @param len
 * @param rangeL min
 * @param rangeR max
 * @param arr pointer to list
 */
void generateRandomArray(int len, int rangeL, int rangeR, int * arr) {
    srand(time(NULL));
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    }
}

/**
 * copy an int array
 * @param len :length
 * @param arr_a :source array
 * @param arr_b :destination array
 */
void copyIntArray(int len, const int * arr_a, int * arr_b) {
    for (int i = 0; i < len; ++i) {
        arr_b[i] = arr_a[i];
    }
}
