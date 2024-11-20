// You are using GCC
// You are using GCC
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int value){
    struct node* node1=(struct node*)malloc(sizeof(struct node*));
    node1->data=value;
    node1->next=NULL;
    return node1;
}

struct node* insertAtBeg(struct node* head,int value){
    struct node* node1=createnode(value);
    node1->next=head;
    head=node1;
    return node1;
}

struct node* insertAtEnd(struct node* head,int value){
    struct node* node1=createnode(value);
    if(head==NULL) return node1;
    
    struct node* last=head;
    while (last->next!=NULL){
        last=last->next;
    }
    last->next=node1;
    return head;
}

struct node* insertAtPosition(struct node* head, int data, int position) {
    struct node* newNode = createnode(data);
    if (position == 1) {
        
        newNode=insertAtBeg(head,data);
    }
    struct node* temp = head;
    int count =1;
    for (int i = 1; i < position - 1 && temp != NULL && count<position-1; i++) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        return 0;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

struct node* deleteAtBeginning(struct node* head) {
    if (head == NULL) return 0;
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* deleteAtpos(struct node* head,int pos){
    struct node* prev;
    struct node* temp=head;
    
    for(int i=1;temp!=NULL && i<pos;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    return head;
}

struct node* deleteAtEnd(struct node* head){
    // struct node* prev;
    // struct node* temp=head;
    
    // while(temp->next!=NULL){
    //     prev=temp;
    //     temp=temp->next;
    // }
    // prev->next=NULL;
    // free(temp);
    // return head;
    
    struct node* temp=head;
    
    while(temp->next->next!=NULL){
        
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}


void print(struct node* head){
    struct node* t=head;
    while (t!=NULL){
        printf("%d ",t->data);
        
        t=t->next;
    }
}

int main(){
    
    struct node* head=createnode(20);
   
    head=insertAtBeg(head,12);
    head=insertAtEnd(head,55);
    head=insertAtPosition(head,25,2);
    print(head);
    printf("\n");
    head=deleteAtBeginning(head);
    
    print(head);
    printf("\n");
    head=deleteAtpos(head,2);
    print(head);
    printf("\n");
    head=deleteAtEnd(head);
    print(head);
    printf("\n");
    
}
