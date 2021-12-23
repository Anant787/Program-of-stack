//INFIX TO POSTFIX EXPRESSION code
#include<stdio.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top=-1;

void push(char ch)
{
    if(top==MAX-1)
    {
        printf("STACK IS OVERFLOW...");
    }
    else
    {
        top++;
        stack[top]=ch;
    }
}
char pop()
{
    if(top==-1)
    return -1;
    else
    {
        return stack[top--];
    }
}
int priority(char ch)
{
    if(ch=='(')
    return 0;
    if(ch=='+' || ch=='-')
    return 1;
    if(ch=='*' || ch=='/')
    return 2;
    if(ch=='^')
    return 3;

    return 0;
}
int main()
{
    char expression[MAX],*temp,ch;
    printf("ENTER THE EXPRESSION :: ");
    scanf("%s",expression);
    temp=expression;
    printf("POSTFIX EXPRESSION IS :: ");
    while(*temp!='\0')
    {
        if(isalnum(*temp))
        {
            printf("%c",*temp);
        }
        else if(*temp=='(')
         push(*temp);
        else if(*temp==')')
         {
             while(ch=pop()!='(')
             {
                 printf("%c",ch);
             }
         }
         else
         {
             while(priority(stack[top])>=priority(*temp))
             {
                printf("%c",pop()); 
             }
             push(*temp);
         }
         temp++;
    }
    while(top!=-1)
     printf("%c",pop());
    return 0; 
}
