#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
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

typedef struct String{
    unsigned int size;
    char *str;
}String;

int ParenMatch(String *par_str);

Stack* createStack();
char returnPopped(Stack* s);
int main(){
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;
    char temp[50];
    
    scanf("%s",temp);
    String *par_str = malloc(sizeof(String));
    par_str->size = 0;
    // store the length of the temp in par_str->size
    // Assign the characters temp[i] to par_str->str[i]
    par_str->str=malloc(50);
    for (int i=0;temp[i]!='\0';i++)
        par_str->str[i]=temp[i];
    par_str->size=strlen(temp);
    par_str->str[par_str->size] = '\0';
    int match = ParenMatch(par_str);
    printf("%d\n", match);

    return 0;
}

Stack* createStack()    //function defined to dynamically allocate memory to stack
{
    Stack* temp;
    temp=(Stack*)malloc(sizeof(Stack));
    temp->size=0;
    return temp;
}

void print_stack(Stack* s)      //Function defined to print the stack top to bottom
{
    struct node* temp=(struct node*)malloc(sizeof(struct node*));
    temp=s->head;
    if (s->size==0)
    {
        exit(1);
    }
    int i=0;
    while(i<s->size)
    {
        printf("%c",temp->data);
        temp=temp->next;
        i+=1;
    }

    printf("\n");
}

void print_stack_reverse(Stack* s)      //Function defined to print stack bottom to top
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=s->head;
    if (s->size==0)
    {
        exit(1);
    }
    else
    {
        int i=0;
        char str[s->size];                  //array defined to store characters of the stack 
        while(i<s->size)    
        {
            str[i]=temp->data;              
            temp=temp->next;
            i+=1;
        }
        for (int i=s->size-1;i>-1;i--)
        {
            printf("%c",str[i]);
        }
    }
    printf("\n");
}

void push( Stack* s , char val)         //function defined to push the elements onto the stack
{
    if(s->size>50)              // Condition to check if the stack is overflown
    {
        exit(1);
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if (s->head==NULL)
    {
    temp->data=val;
    temp->next=NULL;
    }
    else
    {
        temp->data=val;
        temp->next=s->head;
    }
    s->head=temp;
    s->size+=1;
}
void pop( Stack* s)         // function defined to pop the topmost element
{
        s->head=s->head->next;
        s->size--;
}

char top(Stack* s)          //function defined to return the popped item
{
    if (s->size==0)
    return '\0';
    return s->head->data;
}
char returnPopped( Stack* s)      //Pop the topmost element from Stack and return the popped element
{
    if (s->size==0)             // Condition to check is stack empty-stack underflow
    {
        return '\0';
    }
    char top_prev=s->head->data;
    struct node*temp=s->head;
    s->head=s->head->next;
    free(temp);
    s->size--;
    return top_prev;
}

int ParenMatch(String* par_str){//Function defined to check the balance of the equation    
    Stack *s=createStack();
    char ch, top;
    for (int i=0;i<par_str->size;i++)//Traversing the string. 
    {
        ch=par_str->str[i];
        if (ch=='(')                //when an opening symbol is encountered, it is pushed onto the stack
        push(s,'(');
        else if (ch=='[')
        push(s,'[');
        else if (ch=='{')
        {
            push(s,'{');
        }
        else//when a closing symbol is encountered, and they do not match the top of the stack, return 0. 
        {
            top=returnPopped(s);
            if (ch==')'&&top!='(')
            {
                return 0;
            }
            if (ch==']'&&top!='[')
            {
                return 0;
            }
            if (ch=='}'&&top!='{')
            {
                return 0;
            }
        }
    }
        
    if (!(s->size==0))  //If the stack is not empty after the traversal, the expression is unbalanced. 
        return 0;
    return 1;               //Else it is balanced. 
}
