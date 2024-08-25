#include<stdio.h>
#include <stdlib.h>

// Define a structure for a Node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};
struct node{    // creating node  structure
    int data;
    struct node* next;
};

void addatbeg(struct node** head,int data) // defining the function to add a newnode in the beginning of the list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node)) ; // allocating space dynamically
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}

void printlist(struct node* head) // function defined to print the list
{
    struct node* current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
}
int main() {
    int n;
    scanf("%d", &n); 
    // Inputting the number of nodes for the linked list
    struct node* head=NULL;
    int num[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);  // Taking data from the user
    }
    for(int i=n-1;i>=0;i--)
    {
        int duplicate=0;
        for(int j=0;j<i;j++)
        {
            if(num[i]==num[j])  //checking for duplicates
            {
                duplicate=1;
                break;
            }
        }
    
        if(!duplicate){
            addatbeg(&head,num[i]); // adding only one occourence of every number
        }
    }
    printlist(head);
    return 0; // Indicates successful completion of the program
}
