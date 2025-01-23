#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node* list1, struct Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    struct Node* mergedHead = NULL;

    if (list1->data <= list2->data) {
        mergedHead = list1;
        mergedHead->next = merge(list1->next, list2);
    } else {
        mergedHead = list2;
        mergedHead->next = merge(list1, list2->next);
    }
    
    return mergedHead;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    // Create first sorted linked list: 1 -> 3 -> 5
    struct Node* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);

    // Create second sorted linked list: 2 -> 4 -> 6
    struct Node* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    // Merge the lists
    struct Node* mergedList = merge(list1, list2);

    // Print the results
    printf("List 1: ");
    printList(list1);
    
    printf("List 2: ");
    printList(list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
