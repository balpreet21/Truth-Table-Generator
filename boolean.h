char stk[25],stk1[25];
int top=-1,l=-1;
int m=-1;
int term[100];


int AND(int x,int y)
{
	if(x==0||y==0)
		return 0;
	else 
		return 1;
}
int OR(int x,int y)
{
	if(x==1||y==1)
		return 1;
	else 
		return 0;
}
int NOT(int x)
{
	return (1-x);
}
int NAND(int x,int y)
{
	return (OR(1-x,1-y));
}
int NOR(int x,int y)
{
	return(AND(1-x,1-y));
}
int XOR(int x,int y)
{
	if(x==y)
		return 0;
	else 
		return 1;
}
int XNOR(int x,int y)
{
	return(XOR(x,1-y));
}
	
int search(char c)
{
	if(c=='('||c==')')
		return 0;
	if(c=='+')
		return 1;
	if(c=='.')
		return 2;
	if(c=='#')
		return 3;
	if(c==39)
		return 4;
	else
		return -1;
}

int prcd(char c,char d)
{
	if(search(c)>=search(d))
		return 2;
	else 
		return 0;		
}

void pop()
{
	top--;
}

void push(char k)
{
	top++;
	stk[top]=k;	
}
void push1(int k)
{
	top++;
	stk1[top]=k;	
}

void evaluate(char a[])
{
	int o1,o2;
	for(int i=0;i<strlen(a);i++)
	{
		if(search(a[i])==-1)
			push1((int)a[i]-48);
		else if(search(a[i]))
		{
			o2=stk1[top];
			pop();
			if(a[i]=='\'')
				push1(NOT(o2));
			else
			{
				o1=stk1[top];
				pop();
				if(a[i]=='+')
					push1(OR(o1,o2));
				else if(a[i]=='.')
					push1(AND(o1,o2));
				else if(a[i]=='#')
					push1(XOR(o1,o2));
			}
		}
	}	
	printf("%d\n",stk1[0]);
	term[++m]=stk1[0];
	pop();
}

void convert1(char a[])
{
	char arr[100];
	for(int i=0;i<strlen(a);i++)
	{
		if(search(a[i])==-1)
				arr[++l]=a[i];
		else if(a[i]==')')
		{
			while(stk[top]!='(')
			{
				arr[++l]=stk[top];
				pop();
			}
			pop();
		}
		else if(a[i]=='(')
			push(a[i]);
		else if(top==-1)
			push(a[i]);
		else 
		{
			while(top!=-1&&prcd(stk[top],a[i]))
			{
				arr[++l]=stk[top];
				pop(); 
		 	}	 
			push(a[i]);
		} 
	}  
 
	while(top!=-1)
	{
		arr[++l]=stk[top];
		pop();
	}

	printf("\nPOSTFIX expression\t");
	for(int i=0;i<=l;i++)
	{
		printf("%c",arr[i]);
		a[i]=arr[i];
		if(i==l)
			a[i+1]='\0';
	}
	printf("\n");

}	
