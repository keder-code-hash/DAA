#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int DFS_VISIT(int **Graph,bool *visited,int vertexNo,int *order,int vertex,int index)
{
	int k=0;
	visited[vertex]=true;
	for(k=0;k<vertexNo;k++)
	{
		if(Graph[vertex][k]==1 && visited[k]==false)
		{
			index=DFS_VISIT(Graph,visited,vertexNo,order,k,index);
		}
	}
	order[index]=vertex;
	return (index-1);
}
void DFS(int **Graph,bool *visited,int vertexNo,int *order,int startVertex)
{
	int i=0,index=vertexNo-1;
	for(int i=0;i<vertexNo;i++)
	{
		order[i]=-1;
	}
	for(i=0;i<vertexNo;i++)
	{
		visited[i]=false;
	}
	for(i=startVertex;i<vertexNo;i++)
	{
		if(visited[i]==false)
		{
			index=DFS_VISIT(Graph,visited,vertexNo,order,i,index);
		}
	}
}
int main()
{
	int **Graph,*order,vertexNo,*start_vertex;
	bool *visited;
	printf("enter the vertex no:-");
	scanf("%d",&vertexNo);
	Graph=(int**)malloc(vertexNo*sizeof(int*));
	for(int i=0;i<vertexNo;i++)
	{
		Graph[i]=(int*)malloc(vertexNo*sizeof(int));
	}
	for(int i=0;i<vertexNo;i++)
	{
		for(int j=0;j<vertexNo;j++)
		{
			scanf("%d",&Graph[i][j]);
		}
	}
	order=(int*)malloc(vertexNo*sizeof(int));
	visited=(bool *)calloc(vertexNo,sizeof(bool));
	start_vertex=(int *)malloc(vertexNo*(sizeof(int)));
	int j=0,count=0;
	for(int i=0;i<vertexNo;i++)
	{
		for(j=0;j<vertexNo;j++)
		{
			if(Graph[j][i]==1)
			{
				break;
			}
		}
		if(j==vertexNo)
		{
			start_vertex[count]=i;
			count++;
		}
	}
//	DFS(Graph,visited,vertexNo,order);
//	for(int i=0;i<vertexNo;i++)
//	{
//		printf(" %d ",order[i]);
//	}
	for(int i=0;i<count;i++)
	{
		DFS(Graph,visited,vertexNo,order,start_vertex[i]);
		for(int i=0;i<vertexNo;i++)
		{
			if(order[i]!=-1)
			{
				printf(" %d ",order[i]);
			}
		}
		printf("\n ");
	}
}
/*

	0 1 0 1 0 0
	0 0 1 1 0 0
	0 0 0 1 1 1
	0 0 0 0 1 1
	0 0 0 0 0 1
	0 0 0 0 0 0
	
	
	0 0 1 0 0 0 0
	0 0 1 1 0 0 0
	0 0 0 0 1 0 0
	0 0 0 0 0 1 0
	0 0 0 0 0 1 0
	0 0 0 0 0 0 1
	0 0 0 0 0 0 0
*/
