#include<stdio.h>
#define N 5

int stack[N];
int top=-1;

void push()
{
    int x;
    printf("ENTER THE DATA :");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("stack is overflow !!!");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}
void pop()
{
    int item;
    if(top== -1)
    {
        printf("stack is underflow :!!!");
    }
    else
    {
        item= stack[top];
        top--;
        printf("%d ",item);
    }
}

void peek()
{
    if(top== -1)
    {
        printf("stack is underflow :!!!");
    }
    else 
    printf("%d ",stack[top]);
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
}

void main()
{
    int ch;
    do
    {
        printf("Enter the choice:\n1:PUSH\n2:POP\n3:PEEK\n4:DISPLAY:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
             break;
            case 2: pop();
            break;
            case 3: peek();
            break;
            case 4: display();
            break;
            default: printf("INVALID CHOICE !!!");
        }
    }
    while(ch!=0);
}

