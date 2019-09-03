#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST_header.h"

int main() {
    Tree root = createTree(10);
    int right_d = getRightDepth(root);
    int left_d = getLeftDepth(root);
    root = insertTree(root, 5, right_d, left_d);
    right_d = getRightDepth(root);
    left_d = getLeftDepth(root);
    root = insertTree(root, 2, right_d, left_d);
    right_d = getRightDepth(root);
    left_d = getLeftDepth(root);
    root = insertTree(root, 20, right_d, left_d);
    right_d = getRightDepth(root);
    left_d = getLeftDepth(root);
    root = insertTree(root, 30, right_d, left_d);
    right_d = getRightDepth(root);
    left_d = getLeftDepth(root);
    root = insertTree(root, 40, right_d, left_d);
    right_d = getRightDepth(root);
    left_d = getLeftDepth(root);
    root = insertTree(root, 50, right_d, left_d);
    right_d = getRightDepth(root);
    left_d = getLeftDepth(root);
    root = insertTree(root, 25, right_d, left_d);
    return 0;
}