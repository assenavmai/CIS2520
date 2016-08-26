/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: FUNCTION DECLARATIONS
 *LAST MODIFICATION: August 1st, 2014
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct FileInformation{
    char * filename;
    char * filepath;
}Manager;

struct AVLTreeNode{

    void * data;
    int balance;
    struct AVLTreeNode * left, * right;
};

struct AVLTree{
    struct AVLTreeNode * root;
    
    int (* compare) (void * data1, void * data2);
    void (* destroy) (void * data);
};

typedef struct AVLTree Tree;
typedef struct AVLTreeNode TreeNode;

/*Wrapper Functions*/

/*Creates the AVL tree
 *@param comparePtr: function ptr fot compare
 *@param destroyPtr: function ptr for destroy
 *Returns the new AVL tree
 */
Tree * createTree(int (* comparePtr) (void * data1, void * data2), void (* destroyPtr) (void *));

/*Destroys AVL Tree
 *@param Tree *: AVL TREE
 * no return
 */
void destroyTree(Tree * toDie);

/*adds to the AVL TREE
 *@param Tree *: AVL TREE
 *@param void *: data
 * no return
 */
void addToTree(Tree * theTree, void * data);

/*checks to see if the node is in the AVL tree
 *@param Tree *: AVL TREE
 *@param void *: data
 * Returns 1 if found, 0 if not
 */
int isInTree(Tree * theTree, void * data);

/*removes from AVL TREE
 *@param Tree *: AVL TREE
 *@param void *: data
 * no return
 */
void removeFromTree(Tree * theTree, void * data);

/*Print Functions*/

/*prints inorder
 *@param TreeNode *: TreeNode pointer
 *@param printNode: function ptr for printNode
 * no return
 */
void printInOrder(TreeNode * node, void (* printNode) (void * data));

/*prints in preorder
 *@param TreeNode *: TreeNode pointer
 *@param printNode: function ptr for printNode
 * no return
 */
void printPreOrder(TreeNode * node, void (* printNode) (void * data));

/*Helper Functions*/

/*find max value of the 2 ints
 *@param int: integer
 *@param int: integer
 *Returns max value of 2 ints
 */
int max(int a, int b);

/*find height in struct
 *@param TreeNode *: TreeNode pointer\
 * returns height (balance)
 */
int height(TreeNode * node);

/*find max value of the 2 ints
 *@param void *: first data item
 *@param void *: second data item
 *return 1 if data1 > data2 , -1 if data1 < data2 and 0 is they are equal
 */
int compare(void * data1, void * data2);

/*creates a node
 *@param void *: data 
 *@param printNode: function ptr for printNode
 * returns the new node
 */
TreeNode * initnode(void * data);

/*finds min value in tree
 *@param TreeNode *: TreeNode pointer
 * returns min value
 */
TreeNode * findMin(TreeNode * node);

/*finds max value in tree
 *@param TreeNode *: TreeNode pointer
 * returns max value
 */
TreeNode * findMax(TreeNode * node);

/*rotates node left
 *@param TreeNode *: TreeNode pointer
 * returns new rotated node
 */
TreeNode * rotateWithLeftChild(TreeNode * oldRoot);

/*rotates node right
 *@param TreeNode *: TreeNode pointer
 * returns new rotated node
 */
TreeNode * rotateWithRightChild(TreeNode * oldRoot);

/*rotates node right then left
 *@param TreeNode *: TreeNode pointer
 * returns new rotated node
 */
TreeNode * doubleRotateWithLeftChild(TreeNode * oldRoot);

/*rotates node left then right
 *@param TreeNode *: TreeNode pointer
 * returns new rotated node
 */
TreeNode * doubleRotateWithRightChild(TreeNode * oldRoot);

/*inserts into the tree - helper
 *@param TreeNode *: TreeNode pointer\
 *@param void *: data
 *@param comparePtr: function ptr for comparePtr
 * returns new node with inserted node
 */
TreeNode * insert(TreeNode * root, void * data1, int (* comparePtr) (void * data1, void * data2));

/*Creates the AVL tree
 *@param comparePtr: function ptr fot compare
 *@param destroyPtr: function ptr for destroy
 *Returns null on failure, returns node if found
 */
TreeNode * find(TreeNode * root, void * data, int (* comparePtr) (void * data1, void * data2));

/*deletes node in the tree - helper
 *@param TreeNode *: TreeNode pointer\
 *@param void *: data
 *@param comparePtr: function ptr for comparePtr
 *@param destroyPtr: function ptr got destroyPtr
 * returns new node with deleted node
 */
TreeNode * delete(TreeNode * root, void * data, int (* comparePtr) (void * data1, void * data2), void (* destroyPtr) (void *));

/*destory node
 *@param void *:  data item
 * no return
 */
void destroy(void * root);

/*File Functions*/

/*creates a node
 *@param char *: filename
 *@param char *: filepath
 * returns node created
 */
Manager * createNode(char * filename, char * filepath);

/*parses input
 *@param char *: input file
 * returns node created
 */
Manager * storeDirectory(char * line);

/*prints node
 *@param void *:  data item
 * no return
 */
void printNode(void * parameter);

/*searches for path name
 *@param TreeNode *: TreeNode pointer
 *@param char *: filename
 * returns new node with deleted node
 */
char * getPath(TreeNode * root, char * name);