//
// Created by hedaqing on 18-7-15.
//

#include <stdlib.h>
#include "../header/myTree.h"


void __generateTree(treeIntNode * root, int * arr, int len, int index){
    if (len <= index) {
        return ;
    }

    root = (treeIntNode*)malloc(sizeof(treeIntNode));
    root->key = arr[index];
    root->lchild = NULL;
    root->rchild = NULL;

    __generateTree(root->lchild, arr, len, 2 * index + 1);
    __generateTree(root->rchild, arr, len, 2 * index + 2);
}

/**
 * generate a binary tree from array
 * @param root
 * @param arr
 * @param len
 * @param index
 */
treeIntNode * generateTree(int * arr, int len){
    treeIntNode * root = NULL;
    if (len <= 0){
        return root;
    }
    __generateTree(root, arr, len, 0);
    return root;
}
