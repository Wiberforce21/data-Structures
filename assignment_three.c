#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

// Function to create a new doubly linked list node
struct DNode* newDNode(int data) {
    struct DNode* temp = (struct DNode*)malloc(sizeof(struct DNode));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Function to add two numbers represented by doubly linked lists
struct DNode* addTwoLists(struct DNode* first, struct DNode* second) {
    struct DNode *result = NULL, *temp, *prev = NULL;

    int carry = 0, sum;

    while (first != NULL || second != NULL || carry) {
        sum = carry;

        if (first != NULL) {
            sum += first->data;
            first = first->next;
        }

        if (second != NULL) {
            sum += second->data;
            second = second->next;
        }

        carry = sum / 10; // Update carry for next iteration
        sum %= 10; // Get the last digit

        // Create a new node for the result
        temp = newDNode(sum);

        // If this is the first digit, set it as head of result
        if (result == NULL) {
            result = temp;
        } else { 
            prev->next = temp; 
            temp->prev = prev; 
        }
        
        prev = temp; // Move prev pointer to current node
    }

    return result; // Return head of result doubly linked list
}

// Function to print the doubly linked list in reverse order for clarity
void printDList(struct DNode* node) {
    struct DNode* last;

    while (node != NULL) {
        last = node; 
        node = node->next; 
    }

    printf("Result in reverse order: ");
    
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev; 
    }
    
    printf("\n");
}

int main() {
   // Create first doubly linked list representing number 259: [2,5,9]
   struct DNode* first = newDNode(2);
   first->next = newDNode(5);
   first->next->prev = first; 
   first->next->next = newDNode(9);
   first->next->next->prev = first->next;

   // Create second doubly linked list representing number 381: [3,8,1]
   struct DNode* second = newDNode(3);
   second->next = newDNode(8);
   second->next->prev = second; 
   second->next->next = newDNode(1);
   second->next->next->prev = second->next;

   // Add the two numbers and get the result in a doubly linked list
   struct DNode* resultList = addTwoLists(first, second);

   // Print the result
   printDList(resultList);

   return 0;
}
