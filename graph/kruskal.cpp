#include<stdio.h>
#include<stdlib.h>
#define max 15
#define MAX 10000
int find(int i,int *parent)
{
   	while(parent[i])
   		i=parent[i];
   	return i;
}
int uni(int i,int j,int *parent)
{
   	if(i!=j)
   	{
   		parent[j]=i;
   		return 1;
   	}
   	return 0;
}
void kruskal(int size,int **adjMat,int *parent,int minCost,int chk){
	int min=0,r=0,c=0,i=0,j=0;
	while(chk<=size+max){
		for( i=1,min=MAX;i<=size;i++){
			for( j=1;j<=size;j++){
				if(min>adjMat[i][j] && adjMat[i][j]!=0){
					min=adjMat[i][j];
					r=i;
					c=j;
				}
			}
		}
		if(uni(find(r,parent),find(c,parent),parent)){
			minCost+=adjMat[r][c];
		}
		adjMat[r][c]=adjMat[c][r]=MAX;
		chk++;
	}
	printf("%d",minCost);
}
int main(){
	int size=0,minCost=0,chk=1,**adjMat,*parent,i=0,j=0;
	scanf("%d",&size);
	parent=(int *)malloc((size+1)*sizeof(int));
	adjMat=(int **)malloc((size+1)*sizeof(int *));
	for(i=0;i<=size;i++){
		adjMat[i]=(int *)malloc((size+1)*sizeof(int));
	}
	for(i=0;i<=size;i++){
		parent[i]=0;
	}
	for(i=1;i<=size;i++){
		for(j=1;j<=size;j++){
			scanf("%d",&adjMat[i][j]);
			if(adjMat[i][j]==0){
				adjMat[i][j]=MAX;
			}
		}
	}
	kruskal(size,adjMat,parent,minCost,chk);
}
