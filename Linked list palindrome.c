#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        exit(1);
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insertatend(struct Node**head, int data)
{
    struct Node* newNode=createNode(data);
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }
    struct Node* current=*head;
    while(current->next !=NULL)
    {
        current=current->next;
    }
    current->next=newNode;
}
struct Node* reverselist(struct Node* head)
{
    struct Node *prev=NULL, *current=head, *next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
bool ispalindrome(struct Node* head)
{
    if(head==NULL || head->next==NULL){
        return true;
    }
    struct Node *slow=head, *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        struct Node* secondhalf=reverselist(slow->next);
        struct Node* firsthalf=head;
        while(secondhalf!=NULL)
        {
            if(firsthalf->data!=secondhalf->data)
            {
                return false;
            }
            firsthalf=firsthalf->next;
            secondhalf=secondhalf->next;
        }
        return true;
        
        
    }
}
void displaylist(struct Node* head){
    struct Node* current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}
int main() {
    int n;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);
    int data;
    struct Node* head=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        insertatend(&head,data);
    }
    if(ispalindrome(head))
    {
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}
