#include<stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};
void addatbeg(struct Node** head, int data) //function to add a node at the beginning of a linkedlist
{   
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
struct Node* rotate(struct Node* head, int k) //function to rotate the list k places to the right.
{
    if(head==NULL || k==0)
    {
        return head;
    }
    int length=1;      // finding length of the liked list
    struct Node* current=head;
    while(current->next!=NULL)
    {
        length++;
        current=current->next;
    }
    k=k%length;   // finding the actual no. of roations required
    if(k==0){
        return head;
    }
    int split=length-k;  // find position to break the linked list
    struct Node* newtail=head;
    for(int i=1;i<split;i++)
    {
        newtail=newtail->next;
    }
    struct Node* newhead=newtail->next;  // break the linked list at the split position
    newtail->next=NULL;
    current=newhead;
    while(current->next!=NULL)
    {
        current=current->next;
    }
    current->next=head;
    return newhead;
}
void printlist(struct Node* node) // funtion to print the liked list
{
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node=node->next;
    }
}
// Main function where the execution starts
int main() {
    int n, k;
    // Inputting the number of nodes for the linked list
    scanf("%d", &n);
    // Input the number of elements then input k value
    int num[n];
    struct Node* head=NULL;
    for(int i=n-1;i>=0;i--) // using an array to input the elements of the linked list
    {
        scanf("%d",&num[i]);
    }
    for(int i=0;i<n;i++)
    {
        addatbeg(&head,num[i]);
    }
    scanf("%d",&k);
    head=rotate(head,k);
    printlist(head);
    return 0; // Indicates successful completion of the program
}
