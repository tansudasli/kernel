/**
 * Works as tree.
 *
 * Basic logic behind binary tree.
 * - Max 2 nodes for a parent and,
 * - left part is smaller than right part!
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

//interfaces
static NODE * create();                //creates root node,
static NODE * initialize(int);         //creates root node and adds to 1st node

NODE * getRoot();                //returns 1st node
NODE * getNodeByData(int);
NODE * getParent(NODE *);
NODE * getChild(NODE *);
NODE[] * getNodesByLevel(int level);    //returns max 2^L count node/ per Level
bool isEmpty();

NODE * insert(int);             //inserts as child to appropriate parent
NODE * delete(int);             //removes 1st node


void display();                 //prints
int size();                     //node count = n = (2^L - 1)
int height();                   //path level = L = log2(n+1)

int search(int);                //search by data
NODE * min();                   //min value in tree
NODE * max();                   //max value in tree


#ifndef ANSI_C_BINARYTREE_H
#define ANSI_C_BINARYTREE_H

#endif //ANSI_C_BINARYTREE_H
