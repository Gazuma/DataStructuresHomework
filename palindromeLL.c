//Problem Statement : Check wheter linked list is palindrome or not
#include<stdio.h>
#include<stdlib.h>

#define size 100

int stack[size];
int top = -1;

void push(int x){
    if(top==size-1){
        printf("Stack is full\n");
        return;
    }
    stack[++top]=x;
}

int pop(){
    if(top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top--];
}

struct node{
    int data;
    struct node* next;
};

typedef struct node llnode;

llnode* createNode(){
    llnode* newNode = (llnode*)malloc(sizeof(llnode));
    newNode->next = NULL; //Good Practice🙂
    printf("Enter data for new node : ");
    scanf("%d",&newNode->data);
    return newNode;
}

llnode* createLL(int numberOfNodes){
    llnode* head = createNode();
    llnode* temp = head;
    for(int i =1;i<numberOfNodes;i++){
        temp->next = createNode();
        temp = temp->next;
    }
    return head;
}

void printLL(llnode* head){
    if(head==NULL){
        printf("Linked list is empty\n");
        return;
    }
    while(head){
        printf("%d->",head->data);
        head = head->next;
    }
}

int isPalindromeLL(llnode* head){
    if(head==NULL){
        printf("Linked list is empty\n");
        return 0;
    }
    llnode* temp = head;
    //Loading linked list elements to stack
    while(temp){
        push(temp->data);
        temp = temp->next;
    }
    //resetting temp to head
    temp = head;
    //comparing to linked list elements while popping
    while(temp){
        if((pop())!=temp->data)
            //if any element mismatch, return 0, i.e., false
            return 0;
        temp = temp->next;
    }
    //loop ends means all elements matched, therefore, returned 1, i.e., true
    return 1;
}

int main(){
    llnode* head; //Variable to hold base address of linked list
    int numberOfNodes; //Variable to take input parameter for creating linked list
    printf("Enter the number of nodes to create for linked list : ");
    scanf("%d",&numberOfNodes);
    head = createLL(numberOfNodes);
    printf("Given linked list : ");
    printLL(head);
    if(isPalindromeLL(head)){
        printf("\nList is palindrome.\n");
    }
    else{
        printf("\nList is not palindrome.\n");
    }
    return 0;
}