#include <stdlib.h>
#include <stdio.h>
struct node{                                    // structure node defined to be able make a linked list
    int data;
    struct node* next;
};
struct node* check_loop(struct node *head)      //function defined to check the presence of an inner loop
{
    struct node* curr1=head;                    //defining two variables to traverse the list to check for loops.
    struct node* curr2=head;
    while(curr2!=NULL && curr2->next!=NULL)
    {
        curr1=curr1->next;
        curr2=curr2->next->next;
        if(curr1==curr2)                        //inner loop detetced
        {
            printf("There is an inner loop\n");
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=NULL;                    //inner loop removed
            printf("loop removed.");
            return head;
        }
    }
    printf("There is no inner loop");           // if no inner loop is detetced
    return NULL;
}
int main()
{
    int n;
    int value;
    struct node* head=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)                    //making a linked list
    {
        struct node* temp=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&value);
        temp->data=value;
        if(head==NULL)
        {
            temp->next=NULL;
            head=temp;
        }
        else
        {   struct node* curr=head;
            while(curr->next!=NULL)         // adding the fist element to the linked list
            {
                curr=curr->next;
            }
            curr->next=temp;
            temp->next=NULL;
        }
        
    }
    struct node* cur= head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=head->next->next;         //creating an inner loop in the linked list
    check_loop(head);
    return 0;
}
