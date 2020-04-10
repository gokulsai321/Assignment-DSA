#include<stdio.h>
int s1[10],s2[10],top1=-1,top2=-1;
void s1push(int e)
{
	s1[++top1]=e;
}
int s1empty()
{
	if(top1==-1)
		return 1;
	else
		return 0;
}
int s2empty()
{
	if(top2==-1)
		return 1;
	else
		return 0;
}
void s2push(int e)
{
	s2[++top2]=e;
}
int s1top()
{
	return s1[top1];
}
int s2top()
{
	return s2[top2];
}
void s1pop()
{
	top1--;
}
void s2pop()
{
	top2--;
}
void pop()
{
	if(top1==-1)
	{
		printf("queue is empty");
	}
	else
	{
		while(s1empty()!=1)
		{
			s2push(s1top());
			s1pop();
		}
		s2pop();
		while(s2empty()!=1)
		{
			s1push(s2top());
			s2pop();
		}
	}
}
void display()
{
	int i=top1;
	if(top1==-1)
	{
		printf("queue is empty");
	}
	else
	{
		for(i=0;i<=top1;i++)
			printf("%d ",s1[i]);
		printf("\n");
	}
}
main()
{
	int i,n,e;
	printf("1)push\n2)pop\n3)display\n4)exit\n");
	do{
		printf("enter the choice\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("enter the element to insert\n");
				scanf("%d",&e);
				s1push(e);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	}while(n!=4);
}