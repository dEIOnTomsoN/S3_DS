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

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create an empty deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// Function to insert element at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct Node* newNode = newNode(data);
    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Function to insert element at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct Node* newNode = newNode(data);
    if (deque->rear == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to remove element from the front of the deque
void deleteFront(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = deque->front;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
}

// Function to remove element from the rear of the deque
void deleteRear(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = deque->rear;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
}

// Function to display the elements of the deque
void display(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node* temp = deque->front;
    printf("Deque elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Deque* deque = createDeque();
    insertFront(deque, 10);
    insertRear(deque, 20);
    insertFront(deque, 5);
    display(deque);
    deleteFront(deque);
    display(deque);
    deleteRear(deque);
    display(deque);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

int deq[SIZE];             // Double Ended Queue Array
int front = -1, rear = -1; // Initial values of front and rear

// To check if Queue is full
bool isFull()
{
    return (rear + 1) % SIZE == front;
}

// To check if Queue is empty
bool isEmpty()
{
    return front == -1 && rear == -1;
}

// Enqueue at Rear
void insertAtRear(int el)
{
    if (isFull())
        printf("\nQueue full");
    else
    {
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        deq[rear] = el;
    }
}
//CSL201 DATA STRUCTURES LAB ----- DEION TOMSONs
// Enqueue at Front
void insertAtfront(int el)
{
    if (isFull())
        printf("\nQueue full");
    else
    {
        if (isEmpty())
            front = rear = 0;
        else
            front = (front + SIZE - 1) % SIZE;
        deq[front] = el;
    }
}

// Dequeue at Front
void deleteAtFront()
{
    if (isEmpty())
        printf("\nQueue Empty");
    else
    {
        int deleted = deq[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
        printf("Deleted: %d", deleted);
    }
}

// Dequeue at Rear
void deleteAtRear()
{
    if (isEmpty())
        printf("\nQueue Empty");
    else
    {
        int deleted = deq[rear];
        if (front == rear)
            front = rear = -1;
        else
            rear = (rear + SIZE - 1) % SIZE;
        printf("Deleted: %d", deleted);
    }
}

// To print all elements in Queue
void Printdeq()
{
    if (isEmpty())
        printf("\nQueue empty");
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
                printf(" %d", deq[i]);
        }
        else
        {
            for (int i = front; i < SIZE; i++)
                printf(" %d", deq[i]);
            for (int i = 0; i <= rear; i++)
                printf(" %d", deq[i]);
        }
    }
}

//=== MAIN FUNCTION ===//
int main()
{
    int ch, element, del;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Enqueue at front");
        printf("\n2.Enqueue at rear");
        printf("\n3.Dequeue at front");
        printf("\n4.Dequeue at rear");
        printf("\n5.Display queue");
        printf("\n6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAtfront(element);
            break;
        case 2:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAtRear(element);
            break;
        case 3:
            deleteAtFront();
            break;
        case 4:
            deleteAtRear();
            break;
        case 5:
            Printdeq();
            break;
        }
    } while (ch < 6);
    
    return 0;
}
