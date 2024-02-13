#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    char data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to check if a string is palindrome using linked list
int isPalindrome(struct Node* head, char* str) {
    int len = strlen(str);
    int i = 0;
    while (head != NULL && i < len / 2) {
        if (head->data != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
        head = head->next;
        i++;
    }
    return 1; // Palindrome
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    struct Node* head = NULL;

    // Constructing linked list from the input string
    for (int i = 0; i < strlen(str); i++) {
        insertEnd(&head, str[i]);
    }

    // Checking if the string is a palindrome
    if (isPalindrome(head, str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
