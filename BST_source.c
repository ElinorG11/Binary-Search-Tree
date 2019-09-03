#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST_header.h"

struct Tree_t{
    int data,left_depth,right_depth;
    Tree left, right;
};

Tree createTree(int data){
    Tree new_tree = malloc(sizeof(new_tree));
    if(new_tree == NULL) return NULL;
    new_tree->data = data;
    new_tree->left = NULL;
    new_tree->right = NULL;
    new_tree->left_depth = 0;
    new_tree->right_depth = 0;
    return new_tree;
}

static Tree insertionAux(Tree root,int data, int right_depth, int left_depth){
    if(root == NULL){
        Tree new_root = createTree(data);
        if( new_root != NULL){
            root = new_root;
            root->right_depth = right_depth + 1;
            root->left_depth = left_depth + 1;
            return root;
        }
        return NULL;
    }
    if(root->data > data){
        if(root->left == NULL){
            root->left = createTree(data);
            root->left_depth = left_depth + 1;
            return root;
        }
        else insertionAux(root->left,data,right_depth,left_depth);
    }
    if(root->data < data){
        if(root->right == NULL){
            root->right = createTree(data);
            root->right_depth = right_depth + 1;
            return root;
        }
        insertionAux(root->right,data,root->right_depth,root->left_depth);
    }
    if(root->data == data){
        return root;
    }
    return root;
}

static Tree rightRotation(Tree root, TreeResult *result){
    if(root == NULL){
        *result = TREE_NULL_ARG;
        return NULL;
    }
    Tree new_root = malloc(sizeof(new_root));
    new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    *result = TREE_SUCCESS;
    destroyTree(root);
    return new_root;
}

static Tree leftRotation(Tree root, TreeResult *result){
    if(root == NULL){
        *result = TREE_NULL_ARG;
        return NULL;
    }
    Tree new_root = malloc(sizeof(new_root));
    new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    *result = TREE_SUCCESS;
    destroyTree(root);
    return new_root;
}

int getRightDepth(Tree tree){
    if(tree == NULL){
        return 0;
    }
    int depth = 1;
    Tree it = tree;
    while(it->right != NULL){
        depth++;
        it = it->right;
    }
    return depth;
}

int getLeftDepth(Tree tree){
    if(tree == NULL){
        return 0;
    }
    int depth = 1;
    Tree it = tree;
    while(it->left != NULL){
        depth++;
        it = it->left;
    }
    return depth;
}

Tree insertTree(Tree root,int data, int right_depth, int left_depth){
    root = insertionAux(root,data,right_depth,left_depth);
    root->right_depth = getRightDepth(root);
    root->left_depth = getLeftDepth(root);
    if(!IsBalancedTree(root)){
        root = balanceTree(root);
    }
    return root;
}



bool IsBalancedTree(Tree root){
    if(root == NULL) return true;
    if(abs(root->left_depth-root->right_depth) <= 1){
        return true;
    } else return false;
}

Tree balanceTree(Tree root){
    if(root == NULL) return NULL;
    while(root->left_depth > root->right_depth + 1){
        TreeResult result;
        root = rightRotation(root, &result);
        if( result != TREE_SUCCESS){
            return NULL;
        }
        root->right_depth = getRightDepth(root);
        root->left_depth = getLeftDepth(root);
    }
    while(root->right_depth > root->left_depth + 1){
        TreeResult result;
        root = leftRotation(root,&result);
        if( result != TREE_SUCCESS){
            return NULL;
        }
        root->right_depth = getRightDepth(root);
        root->left_depth = getLeftDepth(root);
    }
    return root;
}



void destroyTree(Tree root){
    if(root == NULL){
        return;
    }
    destroyTree(root->right);
    destroyTree(root->left);
    root = NULL;
    free(root);
}