#include<stdio.h>
#include<string.h>
char s[20];
int top=-1;
int isoperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int order(char a)
{
	if(a=='*'||a=='/')
	{
		return 2;
	}
	if(a=='+'||a=='-')
	{
		return 1;
	}
}
int highorder(char a,char b)
{
	if(order(a)<=order(b))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isnumeric(char c)
{
	if(c>='0' && c<='9')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isopening(char c)
{
	if(c=='(')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isclosing(char c)
{
	if(c==')')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
char stop()
{
    return s[top];
}
void pop()
{
    top--;
}
void push(char x)
{
    s[++top]=x;
}
void infixtopostfix(char exp[])
{
	int i;
	char res[20]={'\0'},x;
	for(i=0;i<strlen(exp);i++)
	{
		if(isoperator(exp[i])==1)
		{
			while(empty()==0 && highorder(exp[i],stop())==1 && isopening(stop())!=1)
			{
			    x=stop();
				strncat(res,&x,1);
				pop();	
			}
			push(exp[i]);	
		}
		else if(isnumeric(exp[i])==1)
		{
		    x=exp[i];
			strncat(res,&x,1);	
		}
		else if(isopening(exp[i])==1)
		{
			push(exp[i]);
		}
		else if(isclosing(exp[i])==1)
		{
			while(empty()==0 && isopening(stop())!=1)
			{
			    x=stop();
				strncat(res,&x,1);
				pop();
			}
			pop();		
		}	
	}
	while(empty()==0)
	{
	    x=stop();
		strncat(res,&x,1);
		pop();
	}
	printf("Postfix expression is %s ",res);
}
main()
{
    printf("Only Integer values should be entered \n");
	char exp[20],r[20];
	printf("enter the expression");
	scanf("%s",exp);
	printf("Infix expression is %s \n",exp);
	infixtopostfix(exp);
	//printf("%s",r);
}