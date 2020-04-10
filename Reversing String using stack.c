#include<stdio.h>
#include<string.h>
int stack[100],top=-1,n,x,i;
int empty()
{
    if(top==-1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void push(char x)
{
   
    top++;
    stack[top]=x;
   
}
void pop()
{

    top--;
}
char stop()
{
    return stack[top];
}
void reversestr(char *a)
{
    char c;
	int i;
	char res[100]={'\0'};
	for(i=0;i<strlen(a);i++)
	{
		push(a[i]);
	}
	while(empty()!=0)
	{
	    c=stop();
		strncat(res,&c,1);
		pop();
	}
	printf("%s",res);
}
main()
{
	char a[100],res[100];
	printf("enter the string   : ");
	scanf("%s",a);
	printf("\nRevered string is : %s ");
	reversestr(a);
}