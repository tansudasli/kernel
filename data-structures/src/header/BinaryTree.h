#include <stdbool.h>

/**
 * Works as tree. Some of them are
 * <br>
 * - Heap Tree
 * - Binary Tree:  Max 2 nodes for a parent
 * - Binary Search Tree (BST): Sorted data, Max two nodes, Left is smaller than root node. So Inorder traversal gives Ascending order!
 * - B-Tree, B+Tree
 * - AVL tree, is a self-balanced tree to eliminate skewed tree issues
 * - Trie is string tree, so maxNode = count of alphabet.
 *     Consumes more memory (cause every node has maxNode pointers). Some alternatives compressed trie, ternary search tree..
 * - Ternary Search Tree, is less memory consuming version of Trie.
 *
 * <br><br>
 *
 * How to Traverse a tree
 *  a) Breadth First (level order) Traversal
 *  b) Depth First Traversal
 *      i) Inorder     (Left  Root   Right)
 *     ii) Preorder    (Root  Left   Right)
 *    iii) Postorder   (Left  Right  Root)
 *
 *
 * <br><br><br>
 *                      root (1)
 *                 lChild|info|rChild
 *      node (2n)                    node (2n+1)
 *  lChild|info|rChild             lChild|info|rChild
 *
 * @details Nodes have 1 or 2 sub nodes.
 *  normal case (balanced = complete binary): n nodes = (2^level - 1) . So, if we now level count, we can calculate max nodes.
 *     height = L = log2(n+1) . Which will give an idea, about iterations
 *  worst case: there will be n-node and n-level (1 path)
 * <br>
 * <br>Suitable for:
 * 1- (Tree) Hierarchical data (Naturally fits) such as folder, organization structure<br>
 * 2- (Trie tree) Suitable for auto complete, prefix search, nearest neighbor search, spell check etc..
 * @author tansudasli
 */


typedef struct node NODE;
typedef struct header {     //to make O(1) for accessing last node, we need such struct.
    NODE *parent;           //And, global variable is not appropriate if you need to create more than one stack at the same time

    int nodeCount;
} HEADER;
typedef struct data {
    int info;

} DATA;
struct node {
    HEADER header;
    DATA data;

    NODE *left, *right;
};

//interfaces
NODE * create(DATA d);                   //creates root node, return root

NODE * getRoot(NODE **root);             //returns 1st node
NODE * getParent(NODE **root, DATA s);   //todo: in HEADER data, parent node must be hold.

NODE * search(NODE **root, DATA s);
NODE[] * searchByLevel(NODE **root, int level);    //returns max 2^L count node/ per Level

NODE * insert(NODE **root, DATA d);                //inserts as child to appropriate parent
NODE * delete(NODE **root, DATA d);                //removes 1st node


void display(NODE **root);                  //prints
unsigned int size(NODE **root);             //node count = n = (2^L - 1)
unsigned int height(NODE **root);           //path level = L = log2(n+1)
unsigned int depth(NODE **root, NODE **to); //
bool isEmpty(NODE **root);
bool isBalanced(NODE **root, unsigned int k);   //for every node's subtree must |diff(HeightOfLeft - HeightOfRight)| <= k


NODE * min(NODE **root);                 //min value in tree
NODE * max(NODE **root);                 //max value in tree

