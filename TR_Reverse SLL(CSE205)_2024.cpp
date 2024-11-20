#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int value) {
    struct node* node1 = (struct node*)malloc(sizeof(struct node)); // Corrected sizeof
    node1->data = value;
    node1->next = NULL;
    return node1;
}

struct node* insertAtBeg(struct node* head, int value) {
    struct node* node1 = createnode(value);
    node1->next = head;
    head = node1;
    return node1;
}

struct node* insertAtEnd(struct node* head, int value) {
    struct node* node1 = createnode(value);
    if (head == NULL) return node1;

    struct node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = node1;
    return head;
}

struct node* insertAtPosition(struct node* head, int data, int position) {
    if (position == 1) {
        return insertAtBeg(head, data);
    }

    struct node* newNode = createnode(data);
    struct node* temp = head;
    int count = 1;
    
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return head;  // Return head if position is out of bounds
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;  // Missing return fixed
}

struct node* reverse(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

void print(struct node* head) {
    struct node* t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    struct node* head = createnode(20);
   
    head = insertAtBeg(head, 12);
    head = insertAtEnd(head, 55);
    head = insertAtPosition(head, 25, 2);
    print(head);

    head = reverse(head);
    printf("Reversed Linked List:\n");
    print(head);

    return 0;
}
