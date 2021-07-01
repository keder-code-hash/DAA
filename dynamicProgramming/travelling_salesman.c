#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int tab[4][4];
int travellingSalesman(int **Graph,int *set,int position,int startVertex,int vertexNo)
{
	
   	printf("Call(%d)\n", position);
//	set[startVertex]=1;
	set[position] = 0;

	int  k ,flag = 1,globalMin, localMin = INT_MAX, callForVertex;
	for (k = 0; k < vertexNo; k++)
	{
		if(set[k] != 0 && Graph[position][k] != 0){
			globalMin = travellingSalesman(Graph,set,k,startVertex,vertexNo);
			if(globalMin < localMin){
				localMin = globalMin;
				callForVertex = k;
			}
			flag = 0;
		}
	}
	set[position] = 1;
	if(flag){
		tab[position][startVertex]=Graph[position][startVertex];
		printf("(%d) --> (%d) Final Cost: %d\n", position, startVertex, Graph[position][startVertex]);
		return Graph[position][startVertex];
	}
	tab[position][callForVertex]=localMin+Graph[position][callForVertex];
	printf("(%d) --> (%d) Cost: %d\n", callForVertex, position, localMin+Graph[position][callForVertex]);
	return localMin += Graph[position][callForVertex];
}
int main(){
   int **Graph,vertexNo,i=0,j=0,*set;
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
   travellingSalesman(Graph,set,0,0,vertexNo);
   for ( i = 0; i < vertexNo; i++)
   {
       for (j = 0; j< vertexNo; j++)
       {
           printf("%d ",tab[i][j]);
       }
       printf("\n");
   }
}

