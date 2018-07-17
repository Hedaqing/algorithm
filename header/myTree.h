//
// Created by hedaqing on 18-7-15.
//

#ifndef ALGORITHM_MYTREE_H
#define ALGORITHM_MYTREE_H

#endif //ALGORITHM_MYTREE_H

/**
 * binary tree node: int
 */
typedef struct treeNode {
    int key;
    struct treeNode * lchild;
    struct treeNode * rchild;
}treeIntNode;


/**
 * generate a binary tree
 * @param arr
 * @param len
 * @return
 */
treeIntNode * generateTree(int * arr, int len);