#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int DFS_VISIT(int **Graph,bool *visited,int vertexNo,int *order,int vertex,int index)
{
	int k=0;
	visited[vertex]=true;
	for(k=0;k<vertexNo;k++)
	{
		if(Graph[k][vertex]==1 && visited[k]==false)
		{
			index=DFS_VISIT(Graph,visited,vertexNo,order,k,index);
		}
	}
	order[vertexNo-1-index]=vertex;
	return (index-1);
}
void DFS(int **Graph,bool *visited,int vertexNo,int *order)
{
	int i=0,index=vertexNo-1;
	for(i=0;i<vertexNo;i++)
	{
		visited[i]=false;
	}
	for(i=0;i<vertexNo;i++){
		if(visited[i]==false)
		{
			index=DFS_VISIT(Graph,visited,vertexNo,order,i,index);
		}
	}
}
int main()
{
	int **Graph,*order,vertexNo;
	bool *visited;
	printf("enter the vertex no:-");
	scanf("%d",&vertexNo);
	Graph=(int**)malloc(vertexNo*sizeof(int*));
	for(int i=0;i<vertexNo;i++){
		Graph[i]=(int*)malloc(vertexNo*sizeof(int));
	}
	for(int i=0;i<vertexNo;i++){
		for(int j=0;j<vertexNo;j++){
			scanf("%d",&Graph[i][j]);
		}
	}
	order=(int*)malloc(vertexNo*sizeof(int));
	visited=(bool *)calloc(vertexNo,sizeof(bool));
	DFS(Graph,visited,vertexNo,order);
	for(int i=0;i<vertexNo;i++)
	{
		printf(" %d ",order[i]);
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
