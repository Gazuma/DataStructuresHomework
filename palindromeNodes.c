//Problem Statement : Write a function to count how many elements are palindrome
#include<stdio.h>
#include<stdlib.h>

int isPalindrome(int);

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

int palindromeCountLL(llnode* head){
    int count = 0;
    while(head){
        if(isPalindrome(head->data))
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

int isPalindrome(int n){
    if(n<0)
        return 0;
    int rev = 0;
    int rem;
    int temp = n;
    while(temp){
        rem = temp%10;
        rev = rev*10 + rem;
        temp = temp/10;
    }
    if(rev==n)
        return 1;
    return 0;
}

int main(){
    llnode* head; //Variable to hold base address of linked list
    int numberOfNodes; //Variable to take input parameter for creating linked list
    printf("Enter the number of nodes to create for linked list : ");
    scanf("%d",&numberOfNodes);
    head = createLL(numberOfNodes);
    printf("Number of palindrome numbers in linked list : %d\n",palindromeCountLL(head));
    printf("Given linked list : ");
    printLL(head);
    return 0;
}