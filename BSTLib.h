
/*                          BSTlib.h                                      *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 *                                                                        *
 ************************************************************************ */

#ifndef __BST_LIB_H
#define __BST_LIB_H

// Structure to hold each leaf in the tree
typedef struct treeNodes {
    int value;
    struct treeNodes *left;
    struct treeNodes *right;
} node;


/* *****************************
 * Create and insert functions *
 *******************************/

// Function to create the node for the tree
node *createNode(int value);

// Inserts a node into the tree
node *insertNode(node *root, int value);


/* ********************************************
 * Functions to delete nodes in tree + Search *
 **********************************************/

// Deletes the selected node from the binary search tree
node *deleteNode(node *root, int value);

// Returns the node with the lowest value in the tree
node *minNode(node *root);

// Finds the minimum value in the BST
int findMinValue(node *root);

// Returns the node with highest value in the tree
node *maxNode(node *root);

//Finds the max value in the tree and returns its value
int findMaxValue(node *root);

// Finds and returns a selected node
node *findNode(node *root, int target);

// Destroys an entire BST
void DestroyTree(node *root);



/* **************************
 * Functions to print tree  *
 ****************************/



// Prints tree in preorder order
void printPreorder(node *root);

// Prints values in order
void printInorder(node *root);

// Prints tree in post order
void printPostorder(node *root);

// Prints descending order
void printDescending(node *root);



/* *************************************************************
 * Functions to find height, and max/min functions, and other  *
 ***************************************************************/



// Traverses the tree and find the value given
int searchValue(node *root, int target);

// Finds the max value of two integers
int max(int a, int b);

// Finds the minimum value of two integers
int min(int a, int b);

// Finds the height of the tree
int treeHeight(node *root);

// Converts a sorted array to a BST
node *arrayToTree(int array[], int low, int high);

// Turns a BST into an array
int *treeToArray(node *root);

// Tree sum
int treeSum(node *root);

// Finds the total nodes in the tree
int totalNodes(node *root);







/* *****************************
 * Create and insert functions *
 *******************************/



// Creates a leaf of the binary search tree
node *createNode(int value)
{
    // Creates a node and allocates space to it
    node *newNode = NULL;
    newNode=malloc(sizeof(node));
    if (newNode == NULL) {
        exit(1);
    }

    // Sets the value of the new node to the inserted
    newNode->value=value;
    newNode->left=NULL;
    newNode->right=NULL;

    // returns the node to main
    return newNode;
}


// Inserts a node into the binary search tree
node *insertNode(node *root, int value)
{

    // If the root is empty, insert the node at the root
    if (root == NULL) {
        return createNode(value);
    }

    // If the value is less than the root value, recurse left
    else if (value < root->value) {
        root->left = insertNode(root->left, value);
    }

    // If the value is greater than the root value, recurse right
    else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }

    // If the value is already in the tree, do not add it
    else {

    } ;

    return root;
}



/* ***********************************
 * Functions to delete nodes in tree *
 *************************************/



// Function to delete a student from the tree
node *deleteNode(node *root, int value)
{
    node *temp = NULL;

    if (root == NULL) {
        return root;
    }

    //  else go recurse left
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    }

    // else greater recurse right
    else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    }

    //else we found the node
    else {
        // If both the left and right nodes are empty, free the root
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // If the left root is empty, destroy the root node and return the right node
        else if(root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        // If the right root is empty, destroy the root node and return the left node
        else if(root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        // Finds the max value of the left subtree (Predecessor Method), and stores that node into temp
        temp = maxNode(root->left);
        root->value = temp->value;
        root->left=deleteNode(root->left, temp->value);
    }
    // Returns the new tree
    return root;
}


// Destroys a binary search tree
void DestroyTree(node *root)
{
    // If the tree is empty, do end the deletion function
    if(root == NULL) {
        return;
    }

    // Post-order recursion
    DestroyTree(root->left);
    DestroyTree(root->right);

    // Free the node
    free(root);
}


// Finds the minimum node in a BST
node *minNode(node *root)
{
    // If the tree is empty, return null
    if (root == NULL) {
        return NULL;
    }

    // Creates a temporary pointer and traverses the list to the smallest node
    node *temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// Finds the minimum value in the BST
int findMinValue(node *root)
{
    // If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }

    // Creates a temporary pointer and traverses the list to the smallest node
    node *temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->value;
}


// Finds the max node in the tree
node *maxNode(node *root)
{
    if (root == NULL) {
        return NULL;
    }

    // Creates a temporary pointer and traverses the list to the largest node
    node *temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}


// Finds the maximum value in the BST
int findMaxValue(node *root)
{
    if (root == NULL) {
        return 0;
    }

    node *temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->value;
}


// Traverses the binary search tree for a target value, an returns the value if it is found
node *findNode(node *root, int target)
{

    if (root != NULL) {
        // If target is found, print that the target is found
        if(target == root->value) {
            return root;
        }

        // If the target is larger than the current value, recurse left
        if (target > root->value) {
            return findNode(root->right, target);
        }

        // If the target is smaller the current value, recurse left
        else {
            return findNode(root->left, target);
        }
    }

    // If the value was not found, return -1
    else {
        return NULL;
    }

}



/* **************************
 * Functions to print tree  *
 ****************************/



void printPreorder(node *root)
{
    // If the current node is empty, stop printing
    if(root == NULL) {
        return;
    }

    // Print the Middle, recurse Left then Right, and print the middle
    printf("%d ", root->value);
    printPostorder(root->left);
    printPostorder(root->right);
}


void printInorder(node *root)
{
    // If the current node is empty, stop printing
    if(root == NULL) {
        return;
    }

    // Recurse in the order Left, Middle, Right and print the middle
    printInorder(root->left);
    printf("%d ", root->value);
    printInorder(root->right);
}


// Prints the tree in preorder
void printPostorder(node *root)
{
    // If the current node is empty, stop printing
    if(root == NULL) {
        return;
    }

    // Recurse in the order Left, Right, Middle, and print the middle
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->value);
}

void printDescending(node *root)
{
    // If the root is null, then the tree has finished searching
    if(root == NULL) {
        return;
    }
    // Prints reverse order, RML
    printDescending(root->right);
    printf("%d ", root->value);
    printDescending(root->left);
}



/* *********************************************
 * Functions to find height and width of tree  *
 ***********************************************/



// Finds the greater of two integers
int max(int a, int b)
{
    // Ternary operator, "?" represents the "if" and the ":" represents the else
    return (a>b) ? a : b;
}

// Fins the smaller of two integers
int min(int a, int b)
{
    // Ternary operator, "?" represents the "if" and the ":" represents the else
    return (a<b) ? a : b;
}

int treeHeight(node *root)
{
    // If the tree is empty, the height is set to -1
    if (root==NULL) {
        return -1;
    }

    // Recurse and counter each level, go to whichever branch has a higher value
    else {
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }
}



/* *******************************************************
 * Array to tree and tree to array conversion functions  *
 *********************************************************/



// Converts a sorted array to a BST
node *arrayToTree(int array[], int low, int high)
{
    // If low is greater than high, end the insertion
    if (low > high) {
        return NULL;
    }

    // Calculates the middle most value of the binary search tree
    int mid = low + (high - low) / 2;

    // Creates a value at that root node equal to the middlemost value
    node *root = createNode(array[mid]);

    // Sets the left side of the BST
    root->left = arrayToTree(array,low, mid-1);

    // Sets the right of the BST
    root->right = arrayToTree(array, mid+1, high);

    // Returns the new tree
    return root;
}


// Traverses the binary search tree for a target value, an returns the value if it is found
int searchValue(node *root, int target)
{
    if (root != NULL) {
        // If target is found, print that the target is found
        if(target == root->value) {
            return target;
        }

        // If the target is larger than the current value, recurse left
        if (target > root->value) {
            return searchValue(root->right, target);
        }


        // If the target is smaller the current value, recurse left
        else {
            return searchValue(root->left, target);
        }
    }

    // If the value was not found, return -1
    else {
        return 0;
    }

}


// Finds the sum of all values in the tree
int treeSum(node *root)
{
    if(root == NULL) {
        return 0;
    }
    // Recursively sums the values in each node
    return root->value + treeSum(root->left) + treeSum(root->right);

}


// Finds the sum of all values in the tree
int totalNodes(node *root)
{
    // If the node is empty, return 0
    if(root == NULL) {
        return 0;
    }

    // Recursive counts the nodes in the tree
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

#endif // __BST_LIB_H
