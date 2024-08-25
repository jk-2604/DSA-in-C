#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct node {
    int num;                // Data of the node
    struct node *nextptr;   // Address of the next node
} *stnode;                 // Pointer to the starting node
int *head=&stnode;
// Function prototypes
void createNodeList(int n); // Function to create the linked list
void displayList();         // Function to display the linked list
struct node* createNode(int num)
{
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    if (newNode==NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->num=num;
    newNode->nextptr=NULL;
    return newNode;
}
void addatbeg(struct node** head, int num)
{
    struct node* newNode=createNode(num);
    newNode->nextptr=*head;
    *head=newNode;
}
void displayList(struct node** head)
{
    struct node* current=*head;
    while(current!=NULL)
    {
        printf("%d ",current->num);
        current=current->nextptr;
    }
    
}
// Main function
int main() {
    int n;
    scanf("%d", &n);
    createNodeList(n);
    displayList(head);
    return 0;
}

void createNodeList(int n)
{
    int num1[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num1[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        addatbeg(head,num1[i]);
    }
}