/**
 * Works as tree.
 *
 * Basic logic behind heap tree.
 * - Root is the max value node.
 * - Max 2 nodes for a parent! (special type of binary tree)
 * - parent is greater than childs
 *
 *                      root (1)
 *                 lChild|info|rChild
 *      node (2n)                    node (2n+1)
 *  lChild|info|rChild             lChild|info|rChild
 *
 * @details Nodes have 1 or 2 sub nodes.
 *  normal case (balanced = complete binary): n nodes = (2^level - 1) . So, if we now level count, we can calculate max nodes.
 *     height = L = log2(n+1) . Which will give an idea, about iterations
 *  worst case: there will be n-node and n-level (1 path)
 * @author tansudasli
 */


typedef struct node NODE;
struct node {
    int info;

    NODE *lChild, *rChild;
};

NODE *root;                            //1st node

#ifndef ANSI_C_HEAP_H
#define ANSI_C_HEAP_H

#endif //ANSI_C_HEAP_H
