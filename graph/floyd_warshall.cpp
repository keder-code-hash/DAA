#include<stdio.h>
#include<stdlib.h>
#define _INT_MAX 1000001
void floyd_warshall(int **adj_mat,int **pred_mat,int n)
{
	int i=0,j=0,k=0;  
	for(k=0;  k<n;  k++)
	{
		for(i=0;  i<n;  i++)
		{
			for(j=0;   j<n;  j++)
			{
				if(adj_mat[i][j] > adj_mat[i][k]+adj_mat[k][j])
				{
					adj_mat[i][j]=adj_mat[i][k]+adj_mat[k][j];  
					pred_mat[i][j]=k;  
				}
			}
		}
	}
}
int main(){
	int **adj_mat,n,i=0,j=0,**pred_mat;  
	scanf("%d",&n);  
	adj_mat=(int **)malloc(n*sizeof(int *));  
	pred_mat=(int **)malloc(n*sizeof(int *));  
	for(i=0;  i<n;  i++)
	{
		adj_mat[i]=(int *)malloc(n*sizeof(int));  
		pred_mat[i]=(int *)malloc(n*sizeof(int));  
	}
	printf("Enter the distance value as %d if there does not exist any edge.\n",_INT_MAX);  
	for(i=0;  i<n;  i++)
	{
		for(j=0;  j<n;  j++)
		{
			scanf("%d",&adj_mat[i][j]);  
		}
	}
	for(int i=0;  i<n;  i++)
	{
		for(int j=0;  j<n;  j++)
		{
			if(i!=j || (adj_mat[i][j]!=INT_MAX))
			{
				pred_mat[i][j]=i;  
			}
			else
			{
				pred_mat[i][j]=_INT_MAX;  
			}
		}
	}
	floyd_warshall(adj_mat,pred_mat,n);  
	printf("distance Matrix\n");  
	for(i=0;  i<n;  i++)
	{
		for(j=0;  j<n;  j++)
		{
			printf("%d ",adj_mat[i][j]);  
		}
		printf("\n");  
	}
	printf("Predecessor Matrix\n");  
	for(i=0;  i<n;  i++)
	{
		for(j=0;  j<n;  j++)
		{
			printf("%d ",pred_mat[i][j]);  
		}
		printf("\n");  
	}
}
