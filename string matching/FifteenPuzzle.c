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
	// printf("START-->%d ",puzzle[a][b]);
    int i=0,j=0,less=0,flag=b;
    for(i=a;i<size;i++)
    {
        for(j=flag;j<size;j++)
        {
            if(puzzle[i][j]!=0 && puzzle[a][b]>puzzle[i][j])
            {
                less++;
                // printf("%d   ",puzzle[i][j]);
            }
        }
        if(flag)
        {
            flag=0;
        }
    }
    // printf("\n");
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
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(puzzle[i][j]!=0)
            {
                totLess+=LESS(i,j,puzzle,size);
            }
        }
    }
    

    // printf("LESS value-->%d",totLess);
    if((totLess+row+1)%2==0)
    {
        return 0;
    }
    return 1;
}
bool isValid(int i,int j,int size)
{
    if(i>=0 && j>=0 && i<size && j<size) 
        return true;
    else
        return false;
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
    printf("cost-->%d",c);
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
        printf("hiii");
        return;
    }



    if(moves[0]==1)
    {
        //up
        if(isValid(i-1,j,size) )
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
        if(isValid(i,j-1,size))
        {
            swap(&puzzle[i][j],&puzzle[i][j-1]);
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
            swap(&puzzle[i][j],&puzzle[i][j-1]);
        }
    }
    if(moves[3]==1)
    {
        //right
        if(isValid(i,j+1,size) )
        {
            swap(&puzzle[i][j],&puzzle[i][j+1]);
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
            swap(&puzzle[i][j],&puzzle[i][j+1]);
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
        moves[1]=0;
        FifteenPuzzle(puzzle,size,i-1,j,moves);
    }
    else if(branchIndex==1)
    {
        //down
        moves[0]=0;
        swap(&puzzle[i][j],&puzzle[i+1][j]);
        FifteenPuzzle(puzzle,size,i+1,j,moves);
    }
    else if(branchIndex==2)
    {
        //left
        moves[3]=0;
        swap(&puzzle[i][j],&puzzle[i][j-1]);
        FifteenPuzzle(puzzle,size,i,j-1,moves);
    }
    else if(branchIndex==3)
    {
        //right
        moves[2]=0;
        swap(&puzzle[i][j],&puzzle[i][j+1]);
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
    // if(branchValid(spacex,spacey,puzzle,size)==1)
    // {
        FifteenPuzzle(puzzle,size,spacex,spacey,moves);
    // }
    // else{
    //     printf("INVALID BOARD!!");
    // }
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

6 5 4 13 
2 0 8 15
10 9 1 14
12 3 11 7

5 1 2 0
13 11 7 3
6 8 9 4
14 10 15 12


5 1 7 3 
2 11 10 6
9 14 8 12
0 13 4 15
*/
