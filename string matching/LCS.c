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
void LcsStringMatching(char *first,char *second,int length1,int length2,int **cost,char ** trace)
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
void printMatch(int xPos,int yPos,char **trace,char *str1,int *length)
{
    if(xPos==0 && yPos==0)
    {
        return;
    }
    if(trace[xPos][yPos]=='c')
    {
        printMatch(xPos-1,yPos-1,trace,str1,length);
        // printf("index-->%d\n",xPos);
        (*length)++;
        printf("%c",str1[xPos-1]);
    }
    else if(trace[xPos][yPos]=='u')
    {
        printMatch(xPos-1,yPos,trace,str1,length);
    }
    else if(trace[xPos][yPos]=='s')
    {
        printMatch(xPos,yPos-1,trace,str1,length);
    }
    else{
        return;
    }
}
int main()
{
    int len1,len2,i=0,length=0;
    scanf("%d",&len1);
    scanf("%d",&len2);
    char *first=(char *)malloc(len1 * sizeof(char));
    char *second=(char *)malloc(len2 * sizeof(char));
    fflush(stdin);
    fgets(first,len1+1,stdin);
	fflush(stdin);
    fgets(second,len2+1,stdin);
    int **cost=(int **)calloc((len1+1),sizeof(int*));
    char **trace=(char **)calloc(len1+1,sizeof(char*));
    for(i=0;i<=len1;i++)
    {
        trace[i]=(char *)calloc((len2+1),sizeof(char ));
    }
    for(i=0;i<=len1;i++)
    {
        cost[i]=(int *)calloc((len2+1),sizeof(int ));
    }
    LcsStringMatching(first,second,len1+1,len2+1,cost,trace);
    // printDp(len1+1,len2+1,cost);
    // printTrace(len1+1,len2+1,trace);
    printf("MatchedString is:-\n");
    printMatch(len1,len2,trace,first,&length);
    printf("\nLength of Matched String is: %d",length);
}


/*
4
6
abcd
abcden

6
6
ABCDGH
AEDFHR

6
7
AGGTAB
GXTXAYB
*/
