#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node llnode;

llnode* createNode(int data){
    llnode* temp = (llnode*)malloc(sizeof(llnode));
    temp->next = NULL;
    temp->data = data;
}

llnode* addAtBegin(llnode* head,int data){
    if(head == NULL){
        head = createNode(data);
        return head;
    }
    llnode* newHead = createNode(data);
    newHead->next = head;
    return newHead;
}

llnode* addAtEnd(llnode* head,int data){
    if(head == NULL){
        head = createNode(data);
        return head;
    }
    llnode* temp = head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next = createNode(data);
    return head;
}

llnode* binaryLL(int x){
    llnode* head=NULL;
    int bits = 0;
    while(x){
        head = addAtBegin(head,x%2);
        x/=2;
        bits++;
    }
    while(bits<8){
        head = addAtBegin(head,0);
        bits++;
    }
    return head;
}

void showBinaryLL(llnode* head){
    if(head==NULL){
        printf("Linked list is empty");
        return;
    }
    while(head){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}

llnode* bitwiseAndOperation(llnode* num1,llnode* num2){
    llnode* bitwiseAnd = NULL;
    while(num1&&num2){
        if(num1->data==1&&num2->data==1){
            bitwiseAnd = addAtEnd(bitwiseAnd,1);
        }
        else{
            bitwiseAnd = addAtEnd(bitwiseAnd,0);
        }
        num1 = num1->next;
        num2 = num2->next;
    }
    return bitwiseAnd;
}



int main(){
    /*
    Variables Used
    ------------------------------------------------------------------------
    llnode
    ------------------------------------------------------------------------
    num1 : Linked list to store binary of first number
    num2 : linked list to store binary of second number
    ------------------------------------------------------------------------
    int
    ------------------------------------------------------------------------
    data1 : To take input from user for first number
    data2 : To take input from user for second number 
    ------------------------------------------------------------------------
    */
    llnode  *num1=NULL,*num2=NULL,*bitwiseAnd = NULL;
    int data1,data2;
    printf("Enter first number : ");
    scanf("%d",&data1);
    printf("Enter second number : ");
    scanf("%d",&data2);
    num1 = binaryLL(data1);
    printf("%d = ",data1);showBinaryLL(num1);
    num2 = binaryLL(data2);
    printf("%d = ",data2);showBinaryLL(num2);
    bitwiseAnd = bitwiseAndOperation(num1,num2);
    showBinaryLL(bitwiseAnd);
}


