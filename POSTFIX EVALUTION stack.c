//POSTFIX EVALUTION stack
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAX 100

void push(int *stack,int *top,int n)
{
    if(*top==MAX-1)
    {
        printf("STACK IS OVERFLOW.....");
    }
    else
    {
         stack[++(*top)]=n;
    }
}
int pop(int *stack,int *top)
{
    if(*top==-1)
    {
        printf("stack is empty ..");
    }
    else
    {
        return stack[(*top)--];
    }
}
int main()
{
    int stack[MAX],top=-1;
    char ex[MAX],*temp;
    int n,n1,n2,n3;
    printf("ENTER THE POSTFIX EXPRESSION :: ");
    scanf("%s",ex);
    temp=ex;
    while(*temp!=0)
    {
        if(isdigit(*temp))
        {
            n=*temp-48;
            push(stack,&top,n);
        }
        else
        {
            n1=pop(stack,&top);
            n2=pop(stack,&top);
            switch(*temp)
            {
                case '+':n3=n1+n2;
                 break;
                case '-': n3=n2-n1;
                 break;
                case '*':n3=n1*n2;
                 break;
                case '/':n3=n2/n1;
                 break;
            }
            push(stack,&top,n3);
        }
        temp++;
    }
    printf("The postfix evalution of EXPRESSION :: %s is %d ",ex,pop(stack,&top));
    return 0;
}


