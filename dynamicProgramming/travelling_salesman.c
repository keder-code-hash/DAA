#include<stdio.h>
#include<stdlib.h>
int travellingSalesman(int **Graph,int *visited,int startVertex,int **costMatrix,int vertexNo)
{
    if (/* condition */)
    {
        /* code */
    }
    
}
int main(){
    int **Graph,vertexNo,*visited,**costMatrix,i=0,j=0;
    scanf("%d",&vertexNo);
    Graph=(int**)malloc(vertexNo*sizeof(int *));
    for(i=0;i<vertexNo;i++){
        Graph[i]=(int *)malloc(vertexNo*sizeof(int));
    }
    costMatrix=(int**)malloc(vertexNo*sizeof(int *));
    for(i=0;i<vertexNo;i++){
        costMatrix[i]=(int *)malloc(vertexNo*sizeof(int));
    }
    visited=(int*)calloc(sizeof(int),vertexNo);
    for ( i = 0; i < vertexNo; i++)
    {
        for (j = 0; j< vertexNo; j++)
        {
            scanf("%d",&Graph[i][j]);
        }
        
    }
    travellingSalesman(Graph,visited,0,costMatrix,vertexNo);
}

//construct a set for the algo
    //length of the set shold be calculated.