#include<stdio.h>
#include<stdlib.h>
void preparePrefix(char *pat,int length,int *prefArr)
{
	int i=1,j=0;
	while(i<length)
	{
		if(pat[i]==pat[j])
		{
			prefArr[i]=j+1;
			i++;
			j++;
		}
		else
		{
			while(j>0 && pat[i]!=pat[j])
			{
				j--;
				j=prefArr[j];
			}
			prefArr[i]=prefArr[j];
			i++;
		}
	}
//	for(int i=0;i<length;i++)
//	{
//		printf(" %d ",prefArr[i]);
//	}
}
void KMPMatcher(char *pat,char *text,int *prefArr,int patLength,int textLength)
{
	int q=0;
	for(int i=0;i<textLength;i++)
	{
		while(q>0 && pat[q]!=text[i])
		{
			q--;
			q=prefArr[q];
		}
		if(pat[q]==text[i])
		{
			q++;
		}
		if(q==patLength)
		{
			printf("shift to be done at: %d\n",i-patLength+1);
		}
	}
}
int main(void)
{
	int length,textLen;
	scanf("%d",&length);
	scanf("%d",&textLen);
	fflush(stdin);
	char *text=(char*)malloc(textLen*sizeof(char));
	char *pat=(char *)malloc(length * sizeof(char));
	int *prefArr=(int *)calloc(length,sizeof(int));
	fgets(pat,length+1,stdin);
	fflush(stdin);
	fgets(text,textLen+1,stdin);
	preparePrefix(pat,length,prefArr);
	KMPMatcher(pat,text,prefArr,length,textLen);
}

//if doesnot match:
////	go back 1 for j;
////	find prefArr[j] and change the value of j to prefArr[j]
////	then start from initial until it match:
//		if it is a match then break;
//		else if it is not a match and we reach to 0:
//			then break;


//kmp:
//	if pat[i]==text[i]:
//		i++;
//	else:
//		shift pat by i-prefArr[i]


