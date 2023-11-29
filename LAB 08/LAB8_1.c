#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    if (!deque) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    deque->front = deque->rear = NULL;
    return deque;
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertFront(struct Deque* deque, int value) {
    struct Node* newNode = createNode(value);
    if (!deque->front) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void insertRear(struct Deque* deque, int value) {
    struct Node* newNode = createNode(value);
    if (!deque->rear) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int deleteFront(struct Deque* deque) {
    if (!deque->front) {
        printf("Deque is empty.\n");
        exit(1);
    }
    int value = deque->front->data;
    struct Node* temp = deque->front;
    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }
    free(temp);
    return value;
}

int deleteRear(struct Deque* deque) {
    if (!deque->rear) {
        printf("Deque is empty.\n");
        exit(1);
    }
    int value = deque->rear->data;
    struct Node* temp = deque->rear;
    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }
    free(temp);
    return value;
}

int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

void display(struct Deque* deque) {
    struct Node* current = deque->front;
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Deque* deque = createDeque();
    int choice, value;

    while (1) {
        printf("Deque Operations:\n");
        printf("1. Insert at Front (Input Restricted)\n");
        printf("2. Insert at Rear (Output Restricted)\n");
        printf("3. Delete from Front (Input Restricted)\n");
        printf("4. Delete from Rear (Output Restricted)\n");
        printf("5. Display\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front (Input Restricted): ");
                scanf("%d", &value);
                insertFront(deque, value);
                break;

            case 2:
                printf("Enter value to insert at rear (Output Restricted): ");
                scanf("%d", &value);
                insertRear(deque, value);
                break;

            case 3:
                if (!isEmpty(deque)) {
                    int deleted = deleteFront(deque);
                    printf("Deleted value from front (Input Restricted): %d\n", deleted);
                } else {
                    printf("Deque is empty.\n");
                }
                break;

            case 4:
                if (!isEmpty(deque)) {
                    int deleted = deleteRear(deque);
                    printf("Deleted value from rear (Output Restricted): %d\n", deleted);
                } else {
                    printf("Deque is empty.\n");
                }
                break;

            case 5:
                display(deque);
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}