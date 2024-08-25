#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct node {
    int num;
    struct node *preptr;
    struct node *nextptr;
} *stnode, *ennode;
void addatbeg(int data)  // defining a function to add a new node to the start of the doubly linked list
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->num=data;
    newnode->nextptr=NULL; // initiating the nextptr of new node to null
    newnode->preptr=NULL;  //initiating the preptr of new new node to null
    if(stnode==NULL)
    {
        stnode=ennode=newnode;  // creating a new node if the list is empty
        return;
    }
    newnode->nextptr=stnode;
    stnode->preptr=newnode;
    stnode=newnode;
}
void printlist()   // function to print the doubly linked list
{
    struct node* current=stnode;
    while(current!=NULL)
    {
        printf("%d ",current->num);
        current=current->nextptr;
    }
}
int main() {
    int n;
    stnode = NULL;
    ennode = NULL;
    scanf("%d", &n);    // Input the number of nodes
    int data;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);  //inputting the elements in the doubly linke list
        addatbeg(data);
    }
    printlist();  //printing the doubly linked list
    return 0;
}


