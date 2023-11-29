//Write a menu driven program for Binary Search Tree to perform insert, traverse and delete in the BST.For example:- while executing the program it first shows a menu. 1.Create/ Insert into BST 2.Inorder Traverse(Iterative) 3.Delete from BST
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int key;
    struct Node* left, *right;
};
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}
void inorderTraverse(struct Node* root) {
    if(root!=NULL){
    inorderTraverse(root->left);
    printf("%d ", root->key);
    }
}
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Create/Insert into BST\n");
    printf("2. Inorder Traverse\n");
    printf("3. Delete from BST\n");
    printf("4. Exit\n");
}

int main() {
    struct Node* root = NULL;
    int choice, key;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Inorder Traverse: ");
                inorderTraverse(root);
                printf("\n");
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Node with key %d deleted from BST.\n", key);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
