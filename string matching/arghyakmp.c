#include<stdio.h>
#include<stdlib.h>

void calculateLPS(char *pattern, int pattern_length, int *lps) {
	int i=0, j=-1;

	while (i < pattern_length) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = lps[j];
		}
		i++;
		j++;
		lps[i] = j;
	}
}

void displayLPS(int pattern_length, int *lps) {
	int i = 0;
	printf(" hii ");
	for (i=0; i<pattern_length; i++) {
		printf("%d ", lps[i]);
	}
}

int main(void)
{
	int length, *lps;
	scanf("%d",&length);
	
	fflush(stdin);
	lps = (int *)calloc(length,sizeof(int));
	
	
	char *pat=(char *)malloc(length * sizeof(char));
	fgets(pat,length+1,stdin);
	
	// printf("%s",pat);
	calculateLPS(pat,length, lps);
	// printf(" hii from cal \n ");
	displayLPS(length, lps);
}
