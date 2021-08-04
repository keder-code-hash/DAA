#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

void knapsack(int **dp,int row,int col,int *profit,int * weight)
{
    int i=0,w=0;
    for(i=1;i<row;i++)
    {
        for(w=1;w<col;w++)
        {
		if(w < weight[i]){
		 	dp[i][w]=dp[i-1][w];
		}
		else{
			dp[i][w]=max(dp[i-1][w],dp[i-1][w-weight[i]]+profit[i]);
		}
        }
    }
    
}
void printItems(int **dp,int row,int col,int remknap,int remProf,int *profit,int *weight)
{
	if(row==0) return;
	if(remknap==0) return;
	if(dp[row][col]==remProf)
	{
		printf("%d\n",row);
	}
	remknap=remknap-weight[row];
	col=remknap;
	remProf=remProf-profit[row];
	row--;
	printItems(dp,row,col,remknap,remProf,profit,weight);
}
void main()
{
	int size,i=0,j=0,cap;
	scanf("%d",&size);
	int *profit,*weight;
	profit=(int *)calloc((size+1) , sizeof(int));
	weight=(int *)calloc((size+1) , sizeof(int));
	for(i=1;i<=size;i++){
		scanf("%d",&profit[i]);
	}	
	for(i=1;i<=size;i++){
		scanf("%d",&weight[i]);
	}
	scanf("%d",&cap);
	int **dp=(int **)calloc(size+1,sizeof(int *));
	for(i=0;i<=size;i++)
	{
		dp[i]=(int *)calloc(cap+1,sizeof(int));
	}
	knapsack(dp,size+1,cap+1,profit,weight);
	// for(int i=0;i<=4;i++){
    // 	for(int w=0;w<=10;w++){
	// 	printf("%d ",dp[i][w]);	
	// }
	// printf("\n");
    // }
	printf("total Profit: %d\n",dp[size][cap]);
	int remknap=cap,remProf=dp[size][cap];
	printItems(dp,size,cap,remknap,remProf,profit,weight);

}
/*
4
4 20 10 5
2 5 3 2
10

3
60 100 120
10 20 30 
50


*/