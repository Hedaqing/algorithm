//
// Created by hedaqing on 18-7-15.
//

#ifndef ALGORITHM_MYLINK_H
#define ALGORITHM_MYLINK_H

#endif //ALGORITHM_MYLINK_H

/**
 * linked list node: int
 */
typedef struct Node{
    int key;
    struct Node * next;
    struct Node * previous;
}intNode;

/**
 * print int node link
 * @param head
 */
void printeLink(intNode * head);

/**
 * generate int node link
 * @param arr
 * @param len
 * @return
 */
intNode * generateLink(const int * arr, int len);

/**
 * reverse int node link
 * @param head
 * @return
 */
intNode * reverseLink(intNode * head);

/**
 * get the k intNode counted backwards from 1
 * a    b   c   d   e
 * 5    4   3   2   1
 * @param head
 * @param k
 */
intNode * getBackwardsK(intNode * head, int k);