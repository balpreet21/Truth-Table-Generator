#include<stdio.h>
#include<string.h>
#include<math.h>
#include"boolean.h"


int bin[10];
int n;
char a[30],temp[30];


void binary(int x)	
{
	int i=n;
	while(x!=0||i>0)
	{
		bin[--i]=x%2;
		x=x/2;
	}
}

void kmap()
{
	int p,q;
	if(n%2==0)
		p=q=pow(2,n/2);
	else
	{
		p=pow(2,(n-1)/2);
		q=pow(2,(n+1)/2);
	}
	int k[p][q];
	int o=-1;
	
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<q;j++)
			k[i][j]=term[++o];
	
		if(q==4)
		{
			int t=k[i][2];
			k[i][2]=k[i][3];
			k[i][3]=t;
		}
		if(i==1)
			i=2;
		else if(i==3)
			i=1;
		else if(i==2)
			break;
	}
		
	for(int i=0;i<p;i++)
	{
		printf("\t");
		for(int j=0;j<q;j++)
		{
			if(k[i][j]==0)
				printf("0 ");
			else
				printf("1 ");
		}
		printf("\n");
	}
	printf("\n\n");
}


void strcopy(char temp[],char a[])	
{
	for(int i=0;i<strlen(a);i++)
		temp[i]=a[i];
}
	
int main()
{			
	printf("Enter Boolean Expression\t");
	scanf("%s",a);
		
	printf("Enter no. of variables\t");
	scanf("%d",&n);
	char var[n]; int l=-1;
	convert1(a);
	printf("\nTRUTH TABLE\n\n");
	strcopy(temp,a);
	for(int i=65;i<=122;i++)
	{
		for(int j=0;j<strlen(a);j++)
		{
			if(a[j]==(char)i)
			{			
				var[++l]=a[j];
				break;
			}
		}			
		if(i==90)
			i=96;
	}
	for(int i=0;i<=l;i++)
		printf("%c  ",var[i]);
	printf("\tF\n\n");
	for(int i=0;i<pow(2,n);i++)
	{ 
		binary(i);
	for(int f=0;f<=l;f++)
	{
		for(int j=0;j<strlen(a);j++)
		{	
		if(temp[j]==var[f])
			a[j]=(char)(bin[f]+48);
		}
	}
	for(int i=0;i<n;i++)
	printf("%d  ",bin[i]);
	printf("\t");
	evaluate(a);
	}
	printf("\nMINTERMS = ( ");
	for(int i=0;i<pow(2,n);i++)
	{
		if(term[i]==1)
			printf("%d ",i);
	}
	printf(")");
	printf("\tMAXTERMS = ( ");
	for(int i=0;i<pow(2,n);i++)
	{
		if(term[i]==0)
			printf("%d ",i);
	}
	printf(")\n\n");
	printf("K-MAP\n");
	kmap();
	getchar();
}
