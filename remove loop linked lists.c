#include <stdio.h>
#include <stdlib.h>
// Define a structure for a node in the queue
struct Node {
   int data;
   struct Node *next;
};

struct Node* front = NULL; // Declare a pointer to the front of the queue
struct Node* rear = NULL; // Declare a pointer to the rear of the queue

void enqueue(int x);
void dequeue();
void display();
void enqueue(int x)     // function defined to enqeue an integer in the queue.
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    if (front==NULL && rear==NULL)      //condition to check if the queue is empty or not
    {
        temp->next=NULL;
        front=temp;
        rear=temp;
    }
    rear->next=temp;            
    temp->next=NULL;
    rear=temp;                          //updating the rear to the last element of the queue
}
void dequeue()                          //function defined to dequeue the last elemtent from the queue
{
    if(front==rear)                     // condition to check if there is only one element in the queue
    {
        free(front);
        front=NULL;
        rear=NULL;
    }
    struct Node* temp=front;
    front=temp->next;                   //incrmenting the front position 
    free(temp);
}
void display()              //function defined to display the queue
{
    struct Node* curr=front;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
}
int main() {
    int n, m;
    scanf("%d", &n);
    int data;
    for (int i=0;i<n;i++)               //inputting the elemtents of the queue
    {
        scanf("%d",&data);
        enqueue(data);
    }
    dequeue();
    display();
   return 0; // Return from the main function
}

