#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

typedef struct node llnode;

llnode* createNode(int x){
    llnode* temp = (llnode*)malloc(sizeof(llnode));
    temp->next = NULL;
    temp->data = x;
    return temp;
}

llnode* addNode(llnode* head,int data){
    if(head==NULL){
        head = createNode(data);
        return head;
    }
    llnode* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = createNode(data);
    return head;
}

llnode* calculateFactorial(int num){
    if(num==0){
        return createNode(0);
    }
    llnode* fact=createNode(1);
    llnode* temp = fact;
    for(int i =1;i<=num;i++){
        temp = fact;
        int carry=0;
        while(temp){
            //printf("%d %d %d\n",temp->data,i,carry);
            temp->data=(temp->data*i)+carry;
            
            if(temp->data>10){//carry generated
                carry = temp->data/10;
                //printf("%d\n",temp->data);
                temp->data = temp->data%10;
                //when carry remaining till end
                if(temp->next==NULL){
                    while(carry){
                        addNode(fact,carry%10);
                        carry/=10;
                    }
                    break;
                }
            }
            else{
                carry = 0;
            }
            temp=temp->next;
        }
    }
    return fact;
    
}

void printLL(llnode* head){
    while(head){
        printf("%d->",head->data);
        head = head->next;
    }
}

void printFactorial(llnode*head){
    if(head->next==NULL){
        printf("%d",head->data);
    }
    else{
        printFactorial(head->next);
        printf("%d",head->data);
    }

}

int main(){
    /*
    Variables Used
    --TYPE------------------------------------------------------------------
    llnode
    ------------------------------------------------------------------------
    fact : to store factorial of a number in linked list
    --TYPE------------------------------------------------------------------
    int
    ------------------------------------------------------------------------
    data : to take input from the user
    ------------------------------------------------------------------------
    */
    llnode* fact;
    int data;
    printf("Enter number to find factorial : ");
    scanf("%d",&data);
    fact = calculateFactorial(data);
    printFactorial(fact);
}