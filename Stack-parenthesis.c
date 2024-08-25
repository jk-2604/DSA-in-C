#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    char data;
    struct node* next;
}node;

typedef struct Stack{
    struct node* head;
    unsigned int size;
}Stack;

//Stack ADT
void print_stack(Stack* s);
void print_stack_reverse(Stack* s);
void push(Stack* s, char val);
unsigned int count(Stack *s);
void pop(Stack *s);
char top(Stack *s);

void push(Stack *s, char val){  // function to push the character on the stack.
    struct node* newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=s->head;
    s->head=newnode;
    s->size++;                  // incrementing the size of the stack
}
void pop(Stack *s)              //function to pop the yop element of the stack.
{
    if(s->head==NULL)
    {
        printf("Stack Underflow.\n");
    }
    struct node* temp=s->head;
    s->head=s->head->next;
    free(temp);
    s->size--;                  //decrementing the size of the stack
}
void print_stack(Stack *s)      //function to print the elements of the stack
{
    struct node* cur=s->head;
    while(cur!=NULL)
    {
        printf("%c",cur->data);
        cur=cur->next;
    }
}
void print_stack_reverse(Stack *s)  // function to print the stack in the reverse order.
{
    char a[s->size];
    int i=0;
    struct node* cur=s->head;
    while(i<s->size){
        a[i]=cur->data;
        cur=cur->next;
        i++;
    }
    for(int i=s->size-1;i>-1;i--)   //storing the elements of the stack in an array
    {
        printf("%c",a[i]);          //printing the array in the revrse order
    }
    printf("\n");
}
int main(){
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;
    char temp[50];

    scanf("%s",temp);
    for(int i=0;i<50;i++){
        if(temp[i]=='\0')
            break;
        push(s, temp[i]);
    }
    print_stack_reverse(s);
    
    pop(s);

    scanf("%s",temp);
    for(int i=0;i<50;i++){
        if(temp[i]=='\0')
            break;
        push(s, temp[i]);
    }
    print_stack_reverse(s);


    return 0;
}
