#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int count=0;
bool isSafe(int *trace,int i,int j)
{
	for(int x=1; x<=i-1; x++)
	{
		if(trace[x]==j || abs(trace[x]-j)==abs(x-i))
		{
			return false; 
		}
	}
	return true; 
}

void printBoard(int *trace,int n)
{
	printf("\n"); 
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(trace[i]==j)
			{
				printf(" Q "); 
			}
			else
			{
				printf(" . "); 
			}
		}
			printf("\n"); 
	}
	printf("\n"); 
}
void nQueen(int check,int size,int *trace)
{
	for(int i=1; i<=size; i++)
	{
		if(isSafe(trace,check,i)==true)
		{
			trace[check]=i; 
			if(check==size)
			{
				count++;
//				for(int v=1; v<=size; v++)
//				{
//					printf("%d ",trace[v]); 
//				}
				printf("\nChessBoard:->\n");
				printBoard(trace,size); 
				printf("\n"); 
			}
			else
			{
				nQueen(check+1,size,trace); 
			}
		}
	}
}
int main(){
	int *trace,size; 
	printf("enter the no size of board: ");
	scanf("%d",&size);
	trace=(int *)malloc((size+1)*sizeof(int)); 
	for(int i=1; i<=size; i++)
	{
		trace[i]=0; 
	}
	nQueen(1,size,trace); 
	printf("NO of total solution is:->%d ",count);
}
