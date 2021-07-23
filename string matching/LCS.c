#include<stdio.h>
#include<stdlib.h>
void printDp(int row,int col,int **cost)
{
    int i=0,j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d || ",cost[i][j]);
        }
        printf("\n");
    }
}
void printTrace(int row,int col,char **trace)
{
    int i=0,j=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%c || ",trace[i][j]);
        }
        printf("\n");
    }
}
void LcsStringMatching(char *first,char *second,int length1,int length2,int **cost,char **trace)
{
    int i=0,j=0;
    for(i=1;i<length1;i++)
    {
        for(j=1;j<length2;j++)
        {
            if(first[i-1]==second[j-1])
            {
                cost[i][j]=cost[i-1][j-1]+1;
                trace[i][j]='c';
            }
            else
            {
                if(cost[i-1][j]<cost[i][j-1])
                {
                    cost[i][j]=cost[i][j-1];
                    trace[i][j]='s';
                }
                else
                {
                    cost[i][j]=cost[i-1][j];
                    trace[i][j]='u';
                }
            }
        }
    }
}
int main()
{
    int len1,len2,i=0;
    scanf("%d",&len1);
    scanf("%d",&len2);
    fflush(stdin);
    char *first=(char *)malloc(len1 * sizeof(char));
    char *second=(char *)malloc(len2 * sizeof(char));
    int **cost=(int **)calloc((len1),sizeof(int*));
    for(i=0;i<=len1;i++)
    {
        cost[i]=(int *)calloc((len2),sizeof(int ));
    }
    char **trace=(char **)calloc((len1),sizeof(char *));
    for(i=0;i<len1;i++)
    {
        trace[i]=(char *)calloc(len2,sizeof(char));
    }
    fgets(first,len1,stdin);
	fflush(stdin);
    fgets(second,len2,stdin);
    LcsStringMatching(first,second,len1,len2,cost,trace);
    printDp(len1,len2,cost);
    printTrace(len1,len2,trace);
}


/*
4
6
abcd
ascdsn


*/
