#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef BST_DRAFT_BST_HEADER_H
#define BST_DRAFT_BST_HEADER_H

/**Define struct of Binary Search Tree**/
typedef struct Tree_t* Tree;

/**Possible return values of different operations**/
typedef enum {TREE_SUCCESS, TREE_FAIL, TREE_NULL_ARG, TREE_NO_SUCH_ELEMENT, TREE_ELEMENT_ALREADY_EXISTS} TreeResult;

/*
 * Function to create root of binary search tree with data.
 */
Tree createTree(int data);

/*
 * Getter function. returns right depth of the root, or zero if null argument
 * was sent.
 */
int getRightDepth(Tree tree);

/*
 * Getter function. returns left depth of the root, or zero if null argument
 * was sent.
 */
int getLeftDepth(Tree tree);

/*
 * Function to insert new node into the Binary Search Tree.
 * return values: balanced Binary Search Tree or Null if null argument was sent
 */
Tree insertTree(Tree,int,int,int);

/*
 * Function to check if Binary Search Tree is balanced.
 * return values: true if tree is balanced,
 *                false if tree isn't balanced or null argument was sent.
 */
bool IsBalancedTree(Tree);

/*
 * Function to balance Binary Search Tree.
 * return values: Null is Null argument was sent, or balanced tree otherwise
 */
Tree balanceTree(Tree);

/*
 * Function to destroy Binary Search Tree.
 */
void destroyTree(Tree);

#endif //BST_DRAFT_BST_HEADER_H
