/*
 *Name: Vanessa White
 *Student Number: 0832498
 *
 *PURPOSE: Creating functions for the AVL
 *LAST MODIFICATION: August 1st, 2014
 */
#include "bst.h"

/*preconditions: the compare and destroy function pointer is passed in*/
/*post conditions: the tree is created by pointing to the pointers in the struct*/
Tree * createTree(int (* compare) (void * data1, void * data2), void (* destroy) (void *))
{
    /*Initialization of vairables*/
    Tree * newInfo;

    /*if memory cannot be malloced, exit the program*/
    if((newInfo = malloc(sizeof(Tree))) == NULL)
    {
        printf("Out of memory. Aborting.\n");
        exit(0);
    }

    /*point the pointers*/
    newInfo->root = NULL;
    newInfo->compare = compare;
    newInfo->destroy = destroy;

    /*if the node could not be created, exit the program*/
    if(newInfo == NULL)
    {
        printf("Out of memory. Aborting.\n");
        exit(1);
    }

    return newInfo;
}

/*preconditions: an initialized AVL tree is passed in as the parameter*/
/*postconditions: the tree is destroyed from bottom up by calling helper function delete()*/
void destroyTree(Tree * toDie)
{
    TreeNode * node;

    /*find the minimum in the tree and continue to delete the nodes*/
    while(toDie->root != NULL)
    {
        node = findMin(toDie->root);
        toDie->root = delete(toDie->root, node->data, toDie->compare, toDie->destroy);
    }
    free(toDie);
}

/*preconditions: an initialized AVL tree is passed in as the parameter and the data is passed in also*/
/*postconditions: the data is added into the tree using the insert() helper function*/
void addToTree(Tree * theTree, void * data)
{
    /*calling helper*/
    theTree->root = insert(theTree->root, data, theTree->compare);
}

/*preconditions: initialized AVL tree and data is passed in as the parameter*/
/*postconditions: if it is in the tree, 1 will be returned. If not, returns 0. Calls helper find()*/
int isInTree(Tree * theTree, void * data)
{
    TreeNode * root;

    /*calling helper*/
    root = find(theTree->root, data, theTree->compare);

    /*if the search was successful*/
    if(root != NULL)
    {
       /* printNode(theTree->root);*/
        return 1;
    }
    else/*if not*/
    {
        return 0;
    }
    
    return 0;
    
}

/*preconditions: initialized AVL tree and data is passed in as the parameter*/
/*postconditions: calls helper delete() to remove a single node from the tree*/
void removeFromTree(Tree * theTree, void * data)
{
    theTree->root = delete(theTree->root, data, theTree->compare, theTree->destroy);
}

/*preconditions: an initalized TreeNode and the print function pointer is passed in*/
/*postconditions: the nodes are printed in order, of the tree which is alphabetically*/
void printInOrder(TreeNode * theTree, void (* printNode) (void * data))
{
    if(theTree == NULL)
    {
        return;
    }

    /*recursively print the data in order*/
    printInOrder(theTree->left, printNode);
    printNode(theTree->data);
    printInOrder(theTree->right, printNode);
}

/*preconditions: an initalized TreeNode and the print function pointer is passed in*/
/*postconditions: the nodes are printed from bottom up*/
void printPreOrder(TreeNode * theTree, void (* printNode) (void * data))
{
    if(theTree == NULL)
    {
        return;
    }

    /*recursively print the data in preorder*/
    printNode(theTree->data);
    printInOrder(theTree->left, printNode);
    printInOrder(theTree->right, printNode);
}

/*preconditions: two integers are passed in as the parameters*/
/*postconditions: returns a if it is bigger than b, else return b as the max value*/
int max(int a, int b)
{
    return(a > b? a : b);
}

/*preconditions: initialized treenode passed in as parameter*/
/*postconditions: returns the height stored in the struct*/
int height(TreeNode * node)
{
    if(node == NULL)
    {
        return 0;
    }

    return node->balance;
}

/*preconditions: 2 data entries are entered as the parameters
 *postconditions: the 2 data are compared to see where they are placed within the ADT
*/
int compare(void * data1, void * data2)
{
    /*Cast the void * parameters to the TreeNode ADT*/
    Manager * a = (Manager *)data1;
    Manager * b = (Manager *)data2;

    /*If the first filename is bigger than the second one then return a positive number*/
    if(strcmp(a->filename, b->filename) > 0)
    {
        return 1;
    }
    /*if the filename is smaller than the second one, then return a negative number*/
    if(strcmp(a->filename, b->filename) < 0)
    {
        return -1;
    }
    if(strcmp(a->filename, b->filename) == 0)
    {
        return 0;
    }

    return 0;
}

/*preconditions: a void parameter of data is passed in*/
/*postconditions: creates a TreeNode node*/
TreeNode * initnode(void * data)
{
    /*Initialization of vairables*/
    TreeNode * newInfo;

    /*if memory cannot be malloced, exit the program*/
    if((newInfo = malloc(sizeof(TreeNode))) == NULL)
    {
        printf("Out of memory. Aborting.\n");
        exit(0);
    }

    /*create a new node to store into the struct*/
    newInfo->data = data;
    newInfo->balance = 1;
    newInfo->left = NULL;
    newInfo->right = NULL;

    /*if the node could not be created, exit the program*/
    if(newInfo == NULL)
    {
        printf("Out of memory. Aborting.\n");
        exit(1);
    }

    return newInfo;
}

/*preconditions: an Initialized TreeNode ptr is passed in*/
/*postconditions: finds the minimum value in the tree*/
TreeNode * findMin(TreeNode * node)
{
    if(node != NULL)
    {
        while(node->left != NULL)/*continue going left until you get the min val*/
        {
            node = node->left;
        }
    }

    return node;
}

/*preconditions: an Initialized TreeNode ptr is passed in*/
/*postconditions: finds the maximum value in the tree*/
TreeNode * findMax(TreeNode * node)
{
    if(node != NULL)
    {
        while(node->right != NULL)/*continue going right until you get the max val*/
        {
            node = node->right;
        }
    }

    return node;
}

/*preconditions: initialized treenode passed in as parameter*/
/*postconditions: rotates the tree left*/
TreeNode * rotateWithLeftChild(TreeNode * oldRoot)
{
    TreeNode * temp; 

    /*rotation to the right*/
    temp = oldRoot->left;
    oldRoot->left = temp->right;
    temp->right = oldRoot;

    /*update the height of the tree*/
    oldRoot->balance = max(height(oldRoot->left), height(oldRoot->right)) + 1;
    temp->balance = max(height(temp->left), temp->balance) + 1;

    return temp;
}

/*preconditions: initialized treenode passed in as parameter*/
/*postconditions: rotates the tree right*/
TreeNode * rotateWithRightChild(TreeNode * oldRoot)
{
    TreeNode * temp;

    /*rotation to the right*/
    temp = oldRoot->right;
    oldRoot->right = temp->left;
    temp->left = oldRoot;

    /*update the height*/
    oldRoot->balance = max(height(oldRoot->left), height(oldRoot->right)) + 1;
    temp->balance = max(height(temp->right), temp->balance) + 1;

    return temp;
}

/*preconditions: initialized treenode passed in as parameter*/
/*postconditions: rotates the tree right then left*/
TreeNode * doubleRotateWithLeftChild(TreeNode * oldRoot)
{
    /*rotation of left child*/
    oldRoot->left = rotateWithRightChild(oldRoot->left);
    oldRoot = rotateWithLeftChild(oldRoot);

    return oldRoot;
}

/*preconditions: initialized treenode passed in as parameter*/
/*postconditions: rotates the tree left then right*/
TreeNode * doubleRotateWithRightChild(TreeNode * oldRoot)
{
    /*rotation of right child*/
    oldRoot->right = rotateWithLeftChild(oldRoot->right);
    oldRoot = rotateWithRightChild(oldRoot);

    return oldRoot;
}

/*preconditions: initialized treenode, data and compare function pointer is passed in*/
/*postconditions: a node is inserted alphabetically by filename*/
TreeNode * insert(TreeNode * root, void * data, int (* comparePtr) (void * data1, void * data2))
{
    /*Initialize variables*/
    TreeNode * newNode;
    int leftHeight;
    int rightHeight;

    if(root == NULL)/*if the root is null make the data the root*/
    {
        newNode = initnode(data);
        return newNode;
    }
    else
    {
        if(comparePtr(data, root->data) < 0)/*if data < root*/
        {
            root->left = insert(root->left, data, comparePtr);/*insert into the left subtree*/
            
            leftHeight = height(root->left);/*calculate height*/
            rightHeight = height(root->right);
            
            if(leftHeight - rightHeight > 1)/*if the height difference is greater than 1*/
            {
                if(comparePtr(data, root->left->data) < 0)/*if the data < the data in the left subtree*/
                {
                    root = rotateWithLeftChild(root);/*rotate left*/
                }
                else
                {
                    root = doubleRotateWithLeftChild(root);/*double rotate*/
                }
            }
        }
        else if(comparePtr(data, root->data) > 0)/*if data > root*/
        {
            root->right = insert(root->right, data, comparePtr);/*insert into right subtree*/

            leftHeight = height(root->left);/*calculate height*/
            rightHeight = height(root->right);

            if(rightHeight - leftHeight > 1)/*if height difference is greater than 1*/
            {
                if(comparePtr(data, root->left->data) > 0)/*if data > data in the right subtree*/
                {
                    root = rotateWithRightChild(root);/*rotate right*/
                }
                else
                {
                    root = doubleRotateWithRightChild(root);/*double rotate*/
                }
            }            
        }

        root->balance = max(height(root->left), height(root->right)) + 1;/*update the height after balance and insert*/
    } 
    
    return root;
}

/*preconditions: initialized treenode, data and compare function pointer is passed in*/
/*postconditions: a node is searched within the tree*/
TreeNode * find(TreeNode * root, void * data, int (* comparePtr) (void * data1, void * data2))
{

    if(root == NULL)/*if the root is null, return null*/
    {
        return NULL;
    }

    if(comparePtr(data, root->data) == 0)/*if it is in the tree, return the data*/
    {
        return root->data;
    }

    else if(comparePtr(data, root->data) < 0)/*if it is less than the root->data go into the left subtree*/
    {
        return find(root->left, data, comparePtr);
    }
    else if(comparePtr(data, root->data) > 0)/*if it is greater than the root, go into the right subtree*/
    {
        return find(root->right, data, comparePtr);
    }

    return NULL;
}

/*BALANCE*/
/*preconditions: initialized treenode, data and compare and destroy function pointer is passed in*/
/*postconditions: a node is inserted alphabetically by filename*/
TreeNode * delete(TreeNode * root, void * data, int (* comparePtr) (void * data1, void * data2), void (* destroyPtr) (void *))
{
    TreeNode *temp;
    int lHeight, rHeight;

    if (root == NULL)/*if the root is null there is nothing to delete*/
    {
        return root;
    }

    if (compare(data, root->data) > 0)/*if the data is bigger than the root, go into the right subtree*/
    {
        root->right = delete(root->right, data, comparePtr, destroyPtr);/*delete right recursively*/
        
        lHeight = height(root->left);
        rHeight = height(root->right);

        if(rHeight - lHeight > 1)/*if height difference is greater than 1*/
        {
            if(comparePtr(data, root->left->data) > 0)/*if data > data in the right subtree*/
            {
                root = rotateWithRightChild(root);/*rotate right*/
            }
            else
            {
                root = doubleRotateWithRightChild(root);/*double rotate*/
            }
        }  
    }
    else if (compare(data, root->data) < 0)/*if the data is less than the root go into the left subtree*/
    {
        root->left = delete(root->left, data, comparePtr, destroyPtr);/*delete left recursively*/

        lHeight = height(root->left);
        rHeight = height(root->right);

        if(rHeight - lHeight > 1)/*if height difference is greater than 1*/
        {
            if(comparePtr(data, root->left->data) > 0)/*if data > data in the right subtree*/
            {
                root = rotateWithRightChild(root);/*rotate right*/
            }
            else
            {
                root = doubleRotateWithRightChild(root);/*double rotate*/
            }
        } 
    }
    else
    {
        /*if the root left or right is null*/
        if ((root->left == NULL) || (root->right == NULL))
        {
            if (root->left != NULL)/*if the root left is not null*/
            {
                temp = root->left;/*make the temp equal this*/
            }
            else
            {
                temp = root->right;/*else make temp right*/
            }

            if (temp == NULL)/*if temp is null*/
            {
                temp = root;/*temp is the root and make the root null*/
                root = NULL;
            }
            else/*if it only has one child, dereference it*/
            {
                *root = *temp;
            }

            free(temp);
        }
        else/*find the min data in the right subtree and continue to delete it*/
        {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data, comparePtr, destroyPtr);
        }
    }

    if (root == NULL)/*if the root is null after this, return it*/
    {
        return root;
    }


    return root;
}

/*preconditions: data is passed in as the parameter*/
/*postconditions: it is freed*/
void destroy(void * root)
{
    free(root);
}

/*preconditions: a name, food and rating is passed in as the parameters
 *postconditions: new node is stored into the struct
*/
Manager * createNode(char * filename, char * filepath)
{
    /*Initialization of vairables*/
    Manager * newInfo;

    /*if memory cannot be malloced, exit the program*/
    if((newInfo = malloc(sizeof(Manager))) == NULL)
    {
        printf("Out of memory. Aborting.\n");
        exit(0);
    }

    /*create a new node to store into the struct*/
    newInfo->filename = malloc(sizeof(char) * strlen(filename) + 1);
    newInfo->filepath = malloc(sizeof(char) * strlen(filepath) + 1);
    strcpy(newInfo->filename, filename);
    strcpy(newInfo->filepath, filepath);

    /*if the node could not be created, exit the program*/
    if(newInfo == NULL)
    {
        printf("Out of memory. Aborting.\n");
        exit(1);
    }

    return newInfo;
}

/*preconditions: A line from the file is passed in as a parameter
 *postconditions: The line is parsed and stored into the struct
*/
Manager * storeDirectory(char * line)
{
    Manager * head;
    char * file;
    char * path;

    /*strtok and store each word into its own pointer*/
    file = strtok(line, ",");
    path = strtok(NULL, ","); 

    head = createNode(file, path);/*store them into the struct*/

    return head;   
}

/*preconditions: a parameter is passed in and cast to the Restaurant ADT
 *postconditions: the parameter is printed
*/
void printNode(void * data)
{
    /*cast void parameter to Restaurant ADT*/
    Manager * a = (Manager *)data;

    if(a == NULL)
    {
        printf("printNode() NULL parameter\n");
        return;
    }

    /*print out the data in the struct*/
    printf("[%s] -> %s\n", a->filename, a->filepath);
}

/*preconditions: initialized treenode and a file name is passed in
 *postconditions: filepath is returned if found
*/
char * getPath(TreeNode * root, char * filename)
{
    Manager * tmp = NULL;
    int cmp;
    
    if(root->data == NULL)/*if the root is null return null*/
    {
        return NULL;
    }
    else
    {
        tmp = (Manager *)root->data;/*cast the data*/
    }
    if(root->left == NULL || root->right == NULL)
    {
        return NULL;
    }

    cmp = strcmp(filename, tmp->filename);/*get the value of strcmp*/

    if(cmp == 0)/*if they are equal return filepath*/
    {
        return tmp->filepath;
    }
    if(cmp < 0)/*keep sending the left subtree*/
    {
        return getPath(root->left, filename);
    }
    if(cmp > 0)/*keep sending the right subtree*/
    {
        return getPath(root->right, filename);
    }

    if(root->left == NULL || root->right == NULL)
    {
        return NULL;
    }
    else
    {
        return NULL;
    }

    return NULL;

}

