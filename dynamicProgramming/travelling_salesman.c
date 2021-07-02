#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int minimum(int a , int b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}
int printSet(int *set,int vertexNo){
	int i=0,sum=0;
	for(i=0;i<vertexNo;i++){
		printf("%d ",set[i]);
		sum+=set[i];
	}
	printf("\n");
	return sum;
}
int tab[4],count=0;
int travellingSalesman(int **Graph,int *set,int position,int startVertex,int vertexNo)
{
	
//   	printf("Call(%d)\n", position);
//	printSet(set,vertexNo);
	set[position] = 0;
	int  k ,flag = 1,globalMin, localMin = INT_MAX, callForVertex;
	for (k = 0; k < vertexNo; k++)
	{
		if(set[k] != 0 && Graph[position][k] != 0){
			globalMin =travellingSalesman(Graph,set,k,startVertex,vertexNo);
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
	
	
	printSet(set,vertexNo);
//	printf("hellooo");
	printf("vertex sum:--%d \n",printSet(set,vertexNo));
//	if(printSet(set,vertexNo)==vertexNo-1){
//		printf("hola!!!for position-->%d\n",position);
//		tab[position]=localMin+Graph[position][callForVertex];
////		printf("(%d) --> (%d) Cost: %d\n", callForVertex, position, localMin+Graph[position][callForVertex]);
//	}
//	}
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
//   set[0]=0;
	int startVertex=2;
	for(int i=0;i<vertexNo;i++){
		if(Graph[startVertex][i]!=0){
//			printf("hiiiiiiiii\n");
			set[startVertex]=0;
   			travellingSalesman(Graph,set,i,startVertex,vertexNo);
//   			printf("%d ",returnMin);
//   			for(i=0;i<vertexNo;i++){
//		       set[i]=1;
//		   }
		}
	}
   for ( i = 0; i < vertexNo; i++)
   {
//       for (j = 0; j< vertexNo; j++)
//       {
           printf("%d ",tab[i]);
//       }
//       printf("\n");
   }
}
/*
4
0 20 42 25 
20 0 30 34  
42 30 0 10 
25 34 10 0


4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0

*/

