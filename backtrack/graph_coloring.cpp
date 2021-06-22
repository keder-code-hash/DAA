//#include<stdio.h>
//#include<stdlib.h>
//#include<stdbool.h>
//void assignColor(int k,int Graph[4][4],int *x,int totColor,int vertex_no)
//{
//	while(true)
//	{
//		x[k]=(x[k]+1)%(totColor+1);
//		if(x[k]==0)
//		{
//			return;
//		}
//		int i=1;
//		for(i=1;i<=vertex_no;i++)
//		{
//			if(Graph[k][i]!=0 && x[k]==x[i])
//			{
//				break;
//			}
//		}
//		if(i==vertex_no)
//		{
//			return ;
//		}
//	}
//	
//}
//bool mColoring(int *x,int vertex_no,int Graph[4][4],int k,int totColor)
//{
//	while(true)
//	{
//		printf("hii ");
//		assignColor(k,Graph,x,totColor,vertex_no);
//		if(x[k]==0)
//		{
//			return false;
//		}
//		if(k==vertex_no)
//		{
//			for(int i=1;i<vertex_no;i++)
//			{
//				printf(" %d ",x[i]);
//			}
//		}
//		else
//		{
//			mColoring(x,vertex_no,Graph,k+1,totColor);
//		}
//	}
//}
//int main()
//{
//	int size=4,totColor=4;
////	printf("enter the value for vertex number: ");
////	scanf("%d",&size);
////	printf("enter the total number of color: ");
////	scanf("%d",&totColor);
//	int *x;
////	int **Graph;
////	Graph=(int **)malloc((size+1)*sizeof(int *));
////	for(int i=0;i<=size;i++)
////	{
////		Graph[i]=(int *)malloc((size+1)*sizeof(int));
////	}
////	for(int i=1;i<=size;i++)
////	{
////		for(int j=1;i<=size;j++)
////		{
////			scanf("%d",&Graph[i][j]);
////		}
////	}
//	int Graph[4][4]=
//	{
//		{0,1,0,1},
//		{1,0,1,0,},
//		{0,1,0,1},
//		{0,1,0,1}
//	};
//	x=(int *)malloc((size+1)*sizeof(int ));
//	mColoring(x,size,Graph,1,totColor);
//}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void print(int *x,int vertex_no)
{
    for(int i=0;i<vertex_no;i++)
    {
        printf(" %d ",x[i]);
    }
    printf("\n");
}
bool assignColor(int k,int Graph[4][4],int *x,int color,int vertex_no)
{
	for(int i=0;i<vertex_no;i++)
	{
	    if(Graph[k][i]  && x[i]==color)
	    {
	        return false;
	    }
	}
	return true;
}
bool mColoring(int *x,int vertex_no,int Graph[4][4],int k,int totColor)
{
    if(k==vertex_no)
    {
        print(x,vertex_no);
    }
	for(int i=1;i<=totColor;i++)
	{
	    if(assignColor(k,Graph,x,i,vertex_no)==true)
	    {
	        x[k]=i;
	        if(mColoring(x,vertex_no,Graph,k+1,totColor))
	        {
	            return true;
	        }
	        x[k]=0;
	    }
	}
	 return false; 
}
int main()
{
	int size=4,totColor=3;
	int *x;
	int Graph[4][4]={
    {0,1,0,1},
	{1,0,1,0,},
	{0,1,0,1},
	{0,1,0,1}};
	x=(int *)malloc(size*sizeof(int ));
	for(int i=0;i<size;i++){
	    x[i]=0;
	}
	mColoring(x,size,Graph,0,totColor);
}
