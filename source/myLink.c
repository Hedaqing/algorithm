//
// Created by hedaqing on 18-7-15.
//

#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include "../header/myLink.h"

/**
 * print int node link
 * @param head
 */
void printeLink(intNode * head) {
    intNode * temp = head;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

intNode * generateLink(const int * arr, int len) {
    intNode * head = NULL;
    intNode * tail = NULL;

    if (len > 0) {
        head = (intNode * )malloc(sizeof(intNode));
        head->next = NULL;
        head->key = arr[0];
        tail = head;
    }

    for (int i = 1; i < len; ++i) {
        intNode * pointer = (intNode*)malloc(sizeof(intNode));
        pointer->key = arr[i];
        tail->next = pointer;
        tail = pointer;
    }
}


/**
 * reverse int node link
 * @param head
 * @return
 */
intNode * reverseLink(intNode * head) {
    intNode * temp = head;
    intNode * r_head = head;
    intNode * r_tail = head;
    temp = temp->next;
    while (temp != NULL){
        r_tail->next = temp;
        r_tail = r_tail->next;
        temp = temp->next;
    }

    return r_head;
}


/**
 * get the k intNode counted backwards from 1
 * a    b   c   d   e
 * 5    4   3   2   1
 * @param head
 * @param k
 */
intNode * getBackwardsK(intNode * head, int k){
    intNode * o_head = head;
    intNode * o_pointer = head;
    int counter = 0;
    while (o_head != NULL && counter < k-1){
        o_head = o_head->next;
        counter ++;
    }

    while (o_head != NULL){
        o_head = o_head->next;
        o_pointer = o_pointer->next;
    }

    return o_pointer;
}
