#include <stdio.h>
struct Stack{
    int arr[50];
    int top;
};
void push(struct Stack* stack,int n) // function to push an element to the top of the stack
{
    if(stack->top==49)               // condition to check if the stack is overflowed
    {
        printf("Stack overflow.");
        return;
    }
    stack->arr[++stack->top]=n;     // pushing the number entered by the user to the top of atck
}
int pop(struct Stack* stack,int n)  // function to pop the topmost element from the stack
{
    if(stack->top==-1)              // condition to check if the stack is underflowed
    {
        printf("Stack underflow");
        return-1;
    }
    return stack->arr[stack->top--];
}

int main() {
    int n;
    scanf("%d", &n);
    struct Stack stack;
    int elem;
    stack.top=-1;                //initializing the stack
    for(int i=0;i<n;i++)
    {
        scanf("%d",&elem);       //inputting the numbers on the stack
        push(&stack,elem);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",pop(&stack,i));
    }
    return 0;
}
