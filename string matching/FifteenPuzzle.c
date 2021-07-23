/*
# 15 Puzzle Problem	--Pseudo

bool isValidMove(i, j, size):
	return i, j >= 0 and <= size

int LESS(i, j, matrix, size):
	less = 0
	for k=i to size:
		for l=j to size:
			if mat[i,j] > mat[k,l]:
				less++
	return less

int willBranch(row, col, size, matrix):
	if (row % 2 != 0 and col % 2 == 0):
		X = 1
	else:
		X = 0

	sumLess = cost = 0
	for i=0 to size:
		for j=0 to size:
			if [i,j] != [row,col]:
				temp = LESS[i,j]
				if temp:
					cost++
					sumLess += temp

	if (sumLess - X) % 2 == 0:
		return cost


void recursiveFunc(i, j, size, matrix, moves=[T, T, T, T]):
	if (cost == 0 and empty_slot == matrix[size][size]):
		return

	for i in range(len(moves)):
		if moves[i]:
			switch (i):
				case 0:
					// up
				case 1:
					// down
				case 2:
					// left
				case 3:
					// right
				default:
					break;

int LESS(int **puzzle,int size,int x,int i,int j)
{
    int less=0,k=0,l=0;
    if(j==size && i<size)
    {
        k=i+1;
    }
    for(k=0;k<size;k++)
    {
        for(l=0;l<size;l++)
        {
            if((k>=i && l>=j) && puzzle[k][l]!=0  && puzzle[i][j]>puzzle[k][l] )
            {
                printf("%d ",puzzle[k][l]);
                less++;
            }
        }
    }
    return less;
}
moves=u,d,l,r;
*/




#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int finalMat[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
void printPuzzle(int **puzzle,int size)
{
    int i=0,j=0;
    for(i=0;i<size;i++)
    {
        printf("\n");
        for(j=0;j<size;j++)
        {
            printf("%d ",puzzle[i][j]);
        }

    }
    printf("\n");
}
int swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int LESS(int a,int b,int **puzzle,int size)
{
    int i=0,j=0,less=0;
    for(i=a;i<size;i++)
    {
        for(j=b;j<size;j++)
        {
            if(puzzle[i][j]!=0 && puzzle[a][b]>puzzle[i][j])
            {
                less++;
            }
        }
        j=0;
    }
    return less;
}
int branchValid(int row,int col,int **puzzle,int size)
{
    //row col-->space Pos
    int cost=0,totLess=0,x=-1,i=0,j=0,ind=0,less=0;
    //check space value
    if(((row%2==0) && (col%2!=0))||((row%2!=0) && (col%2==0)))
    {
        x=1;
    }
    else{
        x=0;
    }
    for(i=row;i<size;i++)
    {
        for(j=col;j<size;j++)
        {
            if(puzzle[i][i]!=0 && puzzle[row][col])
            {
                totLess+=LESS(i,j,puzzle,size);
            }
        }
        col=0;
    }
    

    printf("LESS value-->%d",totLess);
    if((totLess+x)%2==0)
    {
        return totLess;
    }
    return -1;
}
bool isValid(int i,int j,int size)
{
    return (i>=0 && j>=0 && i<size && j<size);
}
int cost(int **puzzle,int size)
{
    int i=0,j=0,c=0;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(puzzle[i][j] && puzzle[i][j]!=finalMat[i][j])
            {
                c++;
            }
        }
    }
    return c;
}


void FifteenPuzzle(int **puzzle,int size,int i,int j,int *moves)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",moves[i]);
    }
    printPuzzle(puzzle,size);
    printf("\n\n");
    int branchIndex=0;
    int minCost=INT_MAX,tempCost=0;
    if(cost(puzzle,size)==0) 
    {
        return;
    }



    if(moves[0]==1)
    {
        //up
        if(isValid(i-1,j,size))
        {
            //up position is valid.
            swap(&puzzle[i][j],&puzzle[i-1][j]);
            
            //calculate less value for it for checking that will it give a solution && check the cost for it.
            tempCost=cost(puzzle,size);
            printf("upCost-->%d\n",tempCost);
            //if branch is not valid
            if(tempCost>0)
            {
                //if the cost is minimum the go for it.
                if(tempCost<minCost)
                {
                    minCost=tempCost;
                    branchIndex=0;
                }
            }
            swap(&puzzle[i][j],&puzzle[i-1][j]);
        }
    } 
    if(moves[1]==1)
    {
        //down
        if(isValid(i+1,j,size))
        {
            swap(&puzzle[i][j],&puzzle[i+1][j]);
            tempCost=cost(puzzle,size);
            printf("downCost-->%d\n",tempCost);
            if(tempCost>=0){
                if(tempCost<minCost)
                {
                    tempCost=minCost;
                    branchIndex=1;
                }
            }
            swap(&puzzle[i][j],&puzzle[i+1][j]);
        }
    }
    if(moves[2]==1)
    {
        //left
        if(isValid(i,j+1,size))
        {
            swap(&puzzle[i][j],&puzzle[i][j+1]);
            tempCost=cost(puzzle,size);
            printf("leftCost-->%d\n",tempCost);
            if(tempCost>=0)
            {
                if(tempCost<minCost)
                {
                    minCost=tempCost;
                    branchIndex=2;
                }
            }
            swap(&puzzle[i][j],&puzzle[i][j+1]);
        }
    }
    if(moves[3]==1)
    {
        //right
        if(isValid(i,j-1,size))
        {
            swap(&puzzle[i][j],&puzzle[i][j-1]);
            tempCost=cost(puzzle,size);
            printf("rightCost-->%d\n",tempCost);
            if(tempCost>=0)
            {
                if(tempCost<minCost)
                {
                    minCost=tempCost;
                    branchIndex=3;
                }
            }
            swap(&puzzle[i][j],&puzzle[i][j-1]);
        }
    }
    
    printf("branchingIndex-->%d \n",branchIndex);
    printf("minimumCost-->%d\n",minCost);
    //reset moves..
    for(int i=0;i<size;i++)
    {
        moves[i]=1;
    }
    if(branchIndex==0)
    {
        //up
        swap(&puzzle[i][j],&puzzle[i-1][j]);
        moves[0]=0;
        FifteenPuzzle(puzzle,size,i-1,j,moves);
    }
    else if(branchIndex==1)
    {
        //down
        moves[1]=0;
        swap(&puzzle[i][j],&puzzle[i+1][j]);
        FifteenPuzzle(puzzle,size,i+1,j,moves);
    }
    else if(branchIndex==2)
    {
        //left
        moves[2]=0;
        swap(&puzzle[i][j],&puzzle[i][j+1]);
        FifteenPuzzle(puzzle,size,i,j-1,moves);
    }
    else if(branchIndex==3)
    {
        //right
        moves[3]=0;
        swap(&puzzle[i][j],&puzzle[i][j-1]);
        FifteenPuzzle(puzzle,size,i,j+1,moves);
    }

}
int main()
{
    int size=4;
    int i=0,j=0,spacex=0,spacey=0;
    int *moves=(int *)calloc(size,sizeof(int));
    for(i=0;i<4;i++)
    {
        moves[i]=1;
    }
    int **puzzle=(int **)malloc(4*sizeof(int *));
    for(int i=0;i<size;i++)
    {
        puzzle[i]=(int *)malloc(4*sizeof(int ));
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&puzzle[i][j]);
            if(puzzle[i][j]==0)
            {
                spacex=i;
                spacey=j;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(puzzle[i][j]==0)
            {
                spacex=i;
                spacey=j;
            }
        }
    }
    // printf("%d--->%d",spacex,spacey);
    FifteenPuzzle(puzzle,size,spacex,spacey,moves);
    // swap(puzzle[spacex,spacex],puzzle[2,0]);
    // printPuzzle(puzzle,size);
    // printf("%d  ",branchValid(spacex,spacey,puzzle,size));
    // printf("  %d ",cost(puzzle,size));
    return 0;
    
}


/*
1 2 3 4
5 6 0 8
9 10 7 11
13 14 15 12

1 2 3 4
5 6 7 8
9 10 11 0
13 14 15 12
*/