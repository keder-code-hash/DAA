#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int minVal=INT_MAX;
//int dp[4][16];
//int top=-1,stack[7],size=7;
//void push(int element){
//	if(top==size-1){
//		return ;
//	}
//	else{
//		stack[++top]=element;
////		printf("hiii");
//	}
//}
//int pop(){
//	if(top=-1){
//		return 0;
//	}
//	else{
//		int el=stack[top];
//		top--;
//		return el;
//	}
//}
//int isEmpty(){
//	if(top==-1){
//		return 1;
//	}
//	else{
//		return 0;
//	}
//}
//void printStack(){
//	for(int i=0;i<top;i++){
//		printf("%d ",stack[i]);
//	}
//	printf("\n");
//}
int travellingSalesman(int **Graph,int *set,int position,int startVertex,int level,int vertexNo)
{
	set[position] = 0;
	int  k ,flag = 1,globalMin, localMin = INT_MAX, callForVertex;
	for (k = 0; k < vertexNo; k++)
	{
		if(set[k] != 0 && Graph[position][k] != 0)
		{
			globalMin =travellingSalesman(Graph,set,k,startVertex,level,vertexNo)+Graph[position][k];
			if(globalMin < localMin)
			{
				localMin = globalMin;
				callForVertex = k;
			}
			flag = 0;
		}
	}
	set[position] = 1;
	if(flag)
	{
		return Graph[position][startVertex];
	}
	return localMin;
}


void travellingSalesmanTopDown(int **Graph,int *set,int startVertex,int position,int vertexNo,int finalCost){
	set[position]=0;
	int status=1;
	for(int i=0;i<vertexNo;i++){
		if(set[i]!=0 && Graph[position][i]!=0){
			travellingSalesmanTopDown(Graph,set,startVertex,i,vertexNo,finalCost+Graph[position][i]);
			status=0;
		}
	}
	set[position]=1;
	if(status){
		finalCost+=Graph[position][startVertex];
		if(finalCost<minVal){
			minVal=finalCost;
		}
	}
}


int main()
{
   int **Graph,vertexNo,i=0,j=0,*set,startVertex;
   scanf("%d",&vertexNo);
   Graph=(int**)malloc(vertexNo*sizeof(int *));
   for(i=0;i<vertexNo;i++)
   {
       Graph[i]=(int *)malloc(vertexNo*sizeof(int));
   }
   set=(int *)malloc(vertexNo*sizeof(int));
   for(i=0;i<vertexNo;i++)
   {
       set[i]=1;
   }
   for ( i = 0; i < vertexNo; i++)
   {
       for (j = 0; j< vertexNo; j++)
       {
           scanf("%d",&Graph[i][j]);
       }
       
   }
//   printf("Enter the start Vertex: ");
//   scanf("%d",&startVertex);
   int finalCost=0;
//   printf("%d ",travellingSalesman(Graph,set,startVertex,startVertex,0,vertexNo,cost));
   travellingSalesmanTopDown(Graph,set,0,0,vertexNo,finalCost);
   printf("%d ",minVal);
//   printStack(stack,top);
}

/*
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0
*/

