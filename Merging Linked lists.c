#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list with 'n' nodes
struct Node *createNodelist(int n)
{
    if(n<=0)
    {
        return NULL;
    }
    struct Node* head=(struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&(head->data));
    head->next=NULL;
    
    struct Node* temp=head;
    for(int i=1;i<n;i++)
    {
        struct Node* t2=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&(t2->data));
        t2->next=NULL;
        temp->next=t2;
        temp=temp->next;
    }
    return head;
}

// Function to merge two sorted linked lists
struct Node *merge(struct Node *list1, struct Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    if (list1->data <= list2->data)
    {
        list1->next = merge(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = merge(list1, list2->next);
        return list2;
    }
}

// Function to display a linked list
void displaylist(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate merging of two sorted linked lists
int main()
{
    int n1, n2;
    // Inputting the number of nodes for the linked lists
    scanf("%d", &n1);
    struct Node *list1 = createNodelist(n1);

    scanf("%d", &n2);
    struct Node *list2 = createNodelist(n2);

  
    struct Node *mergedList = merge(list1, list2);
    displaylist(mergedList);

    return 0;
}
