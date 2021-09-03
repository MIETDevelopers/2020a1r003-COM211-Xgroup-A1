// Binary Search Tree operations in C

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
// Create a node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder Traversal
void inorder(struct node *root)
{
    if (root != NULL)
    {
        // Traverse left
        inorder(root->left);

        // Traverse root
        printf("%d\t", root->data);

        // Traverse right
        inorder(root->right);
    }
}

// Insert a node
struct node *insert(struct node *node, int data)
{
    // Return a new node if the tree is empty
    if (node == NULL)
    {
        return newNode(data);
    }
    // Traverse to the right place and insert the node
    if (data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }

    return node;
}
// Find the inorder successor
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int data)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;

    // Find the node to be deleted
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        // If the node is with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // If the node has two children
        struct node *temp = minValueNode(root->right);

        // Place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
struct node *searchBST(struct node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data)
    {
        return root;
    }
    else if (root->data > data)
    {
        return searchBST(root->left, data);
    }
    else
    {
        return searchBST(root->right, data);
    }
}
int main()
{
    int choice, insertElement, deleteElement, searchElement;
    do
    {
        printf("\nEnter the operation you want to perform\nPress 1 for insertion\nPress 2 for deletion\nPress 3 for searching an element in the tree\nPress 4 for printing the tree using inorder traversal\nPress 5 to exit the program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to insert\n");
            scanf("%d", &insertElement);
            root = insert(root, insertElement);
            break;

        case 2:
            printf("Enter the value you want to delete in the BST\n");
            scanf("%d", &deleteElement);
            root = deleteNode(root, deleteElement);
            break;

        case 3:
            printf("Enter the element you want to search for\n");
            scanf("%d", &searchElement);
            struct node *temp = searchBST(root, searchElement);
            if (temp != NULL)
            {
                printf("Element Found\n");
            }
            else
            {
                printf("Element not found\n");
            }

            break;

        case 4:
            inorder(root);
            break;

        case 5:
            printf("Quitting the program\n");
            break;

        default:
            printf("Incorrect Option\n");
            break;
        }
    } while (choice != 5);

    return 0;
}