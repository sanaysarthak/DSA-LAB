// Program in C to implement a Binary Search Tree to perform insertion, searching, and display operations.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct Node *search(struct Node *root, int value)
{
    if(root == NULL || root->data == value)
        return root;

    if(value < root->data)
        return search(root->left, value);
        
    else
        return search(root->right, value);
}

void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d \t", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;
    printf("\nBinary Search Tree Operations:\n");

    do {
        printf("\nEnter 1 for Insertion. \nEnter 2 for Searching. \nEnter 3 for Displaying (Inorder Traversal). \nEnter 0 to Exit. \nEnter choice:-\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL)
                    printf("Value %d found in the tree.\n", value);
                else
                    printf("Value %d not found in the tree.\n", value);
                break;

            case 3:
                printf("Inorder traversal of the tree: ");
                inorder(root);
                printf("\n");
                break;

            case 0:
                printf("Exited the program succesfully!\n");
                break;
                
            default: printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while(choice != 0);

    return 0;
}
