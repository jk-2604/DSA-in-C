#include<stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct Node {
    int data;
    struct Node* next;
};
void addatend(struct Node** head,int data){   //funtion defined to add a new node to the end of the list. 
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    struct Node* current=*head;
    while(current->next!=NULL)
    {
        current=current->next;  //traversing to the end node of the list
    }
    current->next=newnode;
}
void printlist(struct Node* head) // function defined to print the list
{
    struct Node* current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}
void swap(struct Node** head)  //function defined to swap the adjacent elements of the list
{
    if((*head)->next==NULL){
        return;
    }
    struct Node* current=*head;
    while(current!=NULL && current->next!=NULL)
    {
        int temp=current->data;
        current->data=current->next->data;
        current->next->data=temp;
        current=current->next->next;
        
    }
}
// Main function to demonstrate swapping pairs in a linked list
int main() {
    int n;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);
    struct Node* head=NULL;
    int data;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        addatend(&head,data);  //inputting the elements of the list
    }
    swap(&head);
    printlist(head);
    return 0;
}
