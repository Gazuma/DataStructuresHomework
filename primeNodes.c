//Problem Statement : Count the number of odd numbers in linked list
#include<stdio.h>
#include<stdlib.h>

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

int primeCountLL(llnode* head){
    int count = 0;
    while(head){
        if(isPrime(head->data))
            count++;
        head=head->next;
    }
    return count;
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

int isPrime(int n){
    if(n<=0)
        return 0;
    for(int i = 2;i*i<=n;i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main(){
    llnode* head; //Variable to hold base address of linked list
    int numberOfNodes; //Variable to take input parameter for creating linked list
    printf("Enter the number of nodes to create for linked list : ");
    scanf("%d",&numberOfNodes);
    head = createLL(numberOfNodes);
    printf("Number of prime numbers in linked list : %d\n",primeCountLL(head));
    printf("Given linked list : ");
    printLL(head);
    return 0;
}