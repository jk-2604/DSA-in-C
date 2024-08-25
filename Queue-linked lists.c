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
// use the code from Q2 for below functions
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

void InfixToPostfix(String *infix, String *postfix);
int prec(char c);
int isoper(char c);
int main(){
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL;
    s->size = 0;
    char temp[50];
    
    scanf("%s",temp);
    String *infix = malloc(sizeof(String));
    infix->size = 0;
    // read the temp into infix structure
    infix->str=malloc(50);
    for(int i=0;i<50&&temp[i]!='\0';i++)
    {
        infix->str[i]=temp[i];
    }
    infix->size=strlen(temp);
    infix->str[infix->size]='\0';
    /*
    String *postfix = malloc(sizeof(String));
    postfix->size = 0;
    postfix->str = NULL;
    // save the postfix expression in postfix string
    InfixToPostfix(infix, postfix);
    */
    String *postfix=malloc(sizeof(struct String));
    postfix->size=0;
    postfix->str=malloc(2*infix->size);//The initial code was not working. 
    InfixToPostfix(infix,postfix);
    printf("%s\n",postfix->str);
    return 0;
    printf("%s\n",postfix->str);
    return 0;
}
void push(Stack *s,char val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=s->head;
    s->head=newnode;
    s->size++;
}
void pop(Stack *s)
{
    struct node* temp=s->head;
    s->head=s->head->next;
    free(temp);
    s->size--;
}
char top(Stack* s){
    if (s->size>0)
    {
        return s->head->data;
    }
    else
    return '\0';
}
int prec(char c)
{
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
int oper(char c)
{
    return c=='-'||c=='+'||c=='*'||c=='/'||c=='^';
}
void InfixToPostfix(String* infix, String* postfix) {               //Converting the infix to the postfix 
    Stack s;
    s.head = NULL;
    s.size = 0;

    int i, j = 0;
    for (i = 0; infix->str[i]; i++) {
        char ch = infix->str[i];

        if (ch >= '0' && ch <= '9') {                               //condition to check if the input is a number. then stores in the postfix stack 
            postfix->str[j++] = ch;
        } else if (oper(ch) || ch == '^') {                         //condition to check if the input is an operator 
            while (s.size > 0 && prec(top(&s)) >= prec(ch)) {       //condition to evaluate the precedence  
                postfix->str[j++] = top(&s);
                pop(&s);
            }
            push(&s, ch);                                           //Push the element onto the stack, if it has higher precedence than the top of the stack. 
            postfix->str[j++] = ' ';
        } else if (ch == '(') {
            push(&s, ch);
        } else if (ch == ')') {                                     //Condition to check if a closing bracket is encountered
            while (s.size > 0 && top(&s) != '(') {
                postfix->str[j++] = top(&s);
                pop(&s);
            }
            if (s.size > 0 && top(&s) == '(') {
                pop(&s);
            } else {
                return;
            }
        }
    }

    while (s.size > 0) {        //after reaching the end, pop all the elements left in the stack adn print them in the postfix expression 
        if (top(&s)=='(') {
            return;
        }
        postfix->str[j++] = top(&s);
        pop(&s);
    }

    postfix->str[j] = '\0';
    postfix->size = j;          //the expression has a size of "j" 
}