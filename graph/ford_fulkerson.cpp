#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 40
int front=-1,rear=-1;
void enqueue(int *q,int el)
{
	if(rear==max-1)
	{
		exit(0);
	}
	else{
		if(rear==-1)
		{
			front=0;
			q[++rear]=el;
		}
		else
		{
			q[++rear]=el;
		}
	}
}
int dequeue(int *q)
{
	if(front==-1||(front>rear))
	{
		exit(0);
	}
	int el=q[front];
	front++;
	return el;
}
bool isEmpty()
{
	if(front==-1 || front > rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool bfs(int **residualGraph, int s, int t, int *q, int *parent)
{
	bool *isVisited; 
	int size=6; 
	isVisited=(bool *)malloc(size*sizeof(bool)); 
	for(int i=0; i<size; i++)
	{
		isVisited[i]=false; 
	}
	isVisited[s]=true; 
	enqueue(q,s); 
	parent[s]=-1; 
	while(!isEmpty())
	{
		int temp=q[front]; 
		dequeue(q); 
		for(int i=0; i<size; i++)
		{
			if(isVisited[i]==false && residualGraph[temp][i] > 0)
			{
				if(i==t)
				{
					parent[i]=temp; 
					return true; 
				}
				enqueue(q,i); 
				parent[i]=temp; 
				isVisited[i]=true; 
			}
		}
	}
	return false; 
}
int min(int x, int y) 
{
  if(x<y)
  {
  	return x; 
  }
  else
  {
  	return y; 
  }
}
void ford_fulkerson(int **graph,int size,int source,int dest)
{
	int **residualGraph,*parent,maxFlow=0,*q; 
	residualGraph=(int **)malloc(size*sizeof(int *)); 
	for(int i=0; i<size; i++)
	{
		residualGraph[i]=(int *)malloc(size*(sizeof(int))); 
	}
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			residualGraph[i][j]=graph[i][j]; 
		}
	}
	
	parent=(int *)malloc(size*(sizeof(int))); 
	
	q=(int *)malloc(max*sizeof(int)); 
	
	while(bfs(residualGraph,0,5,q,parent))
	{
		int flow=INT_MAX; 
		for(int x=dest; x!=source; x=parent[x])
		{
			flow=min(flow,residualGraph[parent[x]][x]); 
		}
		for(int x=dest; x!=source; x=parent[x]){
			if(graph[parent[x]][x]>0){
				residualGraph[parent[x]][x]-=flow; 
			}
			else{
				residualGraph[x][parent[x]]+=flow; 
			}
		}
		maxFlow+=flow; 
		printf("\n %d \n ",maxFlow);     
	}
}
int main()
{
	int **graph,**residualGraph,*stack,*path,size,i=0; 
	size=6;
	graph=(int **)malloc(size*sizeof(int *));
	for(i=0;i<size;i++){
		graph[i]=(int *)malloc(size*(sizeof(int)));
	}
	for(i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			scanf("%d",&graph[i][j]); 
		}
	}
	ford_fulkerson(graph,size,0,5); 
}
