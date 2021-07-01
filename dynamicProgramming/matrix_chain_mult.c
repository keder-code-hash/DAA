#include<stdio.h>
#include<stdlib.h>
#include<limits.h> 
void matrix_mult_order(int **order,int row,int col){
	if(row==col){
		printf("M%d",row);
	}
	else{
		printf("(");
		matrix_mult_order(order,row,order[row][col]);
		matrix_mult_order(order,order[row][col]+1,col);
		printf(")");
	}
}
void matrix_chain(int **syn,int **mat,int n,int *dim){
	int level=0,i=0,j=0,k=0,op=0;
	for(level=2;level<=n;level++){
		for(i=1;i<=n-level+1;i++){
			j=i+level-1;
			mat[i][j]=INT_MAX;
			for(k=i;k<=j-1 && j<n;k++){
				op=mat[i][k]+mat[k+1][j]+(dim[i-1]*dim[k]*dim[j]);
				if(op<mat[i][j]){
					mat[i][j]=op;
					syn[i][j]=k;
				}
			}
		}
	}
}
int main()
{
	int n,**syn,**mat,i=0,j=0,*dim;
	scanf("%d",&n);
	dim=(int *)malloc((n+1)*sizeof(int));
	for(i=1;i<=n;i++){
		scanf("%d",&dim[i]);
	}
	syn=(int **)malloc((n+1)*sizeof(int *));
	for(i=0;i<n+1;i++){
		syn[i]=(int*)malloc((n+1)*sizeof(int));
	}
	mat=(int **)malloc((n+1)*sizeof(int *));
	for(i=0;i<n+1;i++){
		mat[i]=(int*)malloc((n+1)*sizeof(int));
	}
	for(i=1;i<=n;i++){
			mat[i][i]=0;
			syn[i][i]=0;
	}
	matrix_chain(syn,mat,n,dim);
	printf("%d ",mat[1][n-1]);
//	printf("The order is: \n");
//	matrix_mult_order(syn,1,n-1);
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++){
//			printf("%d ",mat[i][j]);
//		}
//		printf("\n");
//	}
}
