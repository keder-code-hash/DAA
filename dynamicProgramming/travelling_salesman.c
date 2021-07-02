#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int travellingSalesman(int **Graph,int *set,int position,int startVertex,int vertexNo)
{
	set[position] = 0;

	int  k ,flag = 1,globalMin, localMin = INT_MAX, callForVertex;
	for (k = 0; k < vertexNo; k++)
	{
		if(set[k] != 0 && Graph[position][k] != 0){
			globalMin =travellingSalesman(Graph,set,k,startVertex,vertexNo)+Graph[position][k];
			if(globalMin < localMin){
				localMin = globalMin;
				callForVertex = k;
			}
			flag = 0;
		}
	}
	set[position] = 1;
	if(flag){
		return Graph[position][startVertex];
	}
	return localMin;
}
int main(){
   int **Graph,vertexNo,i=0,j=0,*set,startVertex;
   scanf("%d",&vertexNo);
   Graph=(int**)malloc(vertexNo*sizeof(int *));
   for(i=0;i<vertexNo;i++){
       Graph[i]=(int *)malloc(vertexNo*sizeof(int));
   }
   set=(int *)malloc(vertexNo*(sizeof(int )));
   for(i=0;i<vertexNo;i++){
       set[i]=1;
   }
   for ( i = 0; i < vertexNo; i++)
   {
       for (j = 0; j< vertexNo; j++)
       {
           scanf("%d",&Graph[i][j]);
       }
       
   }
   printf("Enter the start Vertex: ");
   scanf("%d",&startVertex);
   printf("%d ",travellingSalesman(Graph,set,startVertex,startVertex,vertexNo));
   
}

