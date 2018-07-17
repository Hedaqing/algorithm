#include "../header/mySum.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0;
    int j = 0;
    int rangeI = numsSize -1;
    int rangeJ = numsSize;
    int continueFlag = 1;
    for (i=0; i< rangeI; i++) {
        printf("i is: %d, nums_i is: %d\n", i, nums[i]);
        int targetB = target - nums[i];
        printf("targetB is: %d\n", targetB);
        for (j=i+1; j < rangeJ; j++) {
            printf("j is: %d, nums_j is: %d\n", j, nums[j]);
            if (nums[j] != targetB)
                continue;
            continueFlag = 0;
            break;
        }
        if (!continueFlag)
            break;
    }

    int *ret = (int*)malloc(sizeof(int)*2);
    ret[0] = 0;
    ret[1] = 0;
    if (!continueFlag) {
        ret[0] = i;
        ret[1] = j;
    }
    return ret;
}

/**
 * o(n)
 * @param numbers
 * @param numbersSize
 * @param target
 * @param returnSize
 * @return
 */
int* __twoSumSortedOn(int* numbers, const int numbersSize, int target, int* returnSize) {
    int leftPoint = 0;
    int rightPoint = numbersSize - 1;

    int * ret;
    while(1) {
        if (leftPoint >= rightPoint) {
            *returnSize = 0;
            ret = (int*)malloc(sizeof(int) * *returnSize);
            break;
        }

        if (numbers[leftPoint] + numbers[rightPoint] < target) {
            leftPoint ++;
            continue;
        }

        if (numbers[leftPoint] + numbers[rightPoint] > target) {
            rightPoint --;
            continue;
        }

        if (numbers[leftPoint] + numbers[rightPoint] == target) {
            *returnSize = 2;
            ret = (int*)malloc(sizeof(int) * *returnSize);
            ret[0] = leftPoint + 1;
            ret[1] = rightPoint + 1;
            break;
        }
    }
    return ret;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSumSorted(int* numbers, int numbersSize, int target, int* returnSize) {
    int continueFlag = 0;
    *returnSize = 2;
    int *ret = (int*)malloc(sizeof(int)*2);
    for (int i = 0; i < numbersSize - 1; ++i) {
        int targetB = target - numbers[i];

        for (int j = i+1; j < numbersSize; ++j) {
            if (numbers[j] != targetB)
                continue;
            continueFlag = 1;
            ret[1] = j+1;
            break;
        }

        if (continueFlag){
            ret[0] = i+1;
            break;
        }
        *returnSize = 0;
    }
    return ret;
}

void twoSumMain() {
    printf("in twoSumMain\n");
    int nums[4] = {2,7,11,15};
    int numsSize = 4;
    int target = 9;
    // id: 1, without sorted
    // int *ret = twoSum(nums, numsSize, target);

    // id: 167 sorted array
    int returnSize = 0;
    int *ret;
    ret = twoSumSorted(nums, numsSize, target, &returnSize);

    // print the result
    printf("ret is: %d, %d\n", ret[0], ret[1]);

    // 复杂度为o(1)
    ret = __twoSumSortedOn(nums, numsSize, target, &returnSize);
    printf("ret is: %d, %d\n", ret[0], ret[1]);
}
