#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct job_det
{
	int jod_id;
	int job_dead;
	int profit;
};
void merge(struct job_det *job,int low,int mid,int high)
{
	int size1=(high-low)+1;
	struct job_det *temp1;
	temp1=(struct job_det *)malloc(size1*(sizeof(struct job_det)));
	int first=low,second=mid+1,k=0;
	for(int i=low;i<=high;i++)
	{
		if(first>mid)
		{
			temp1[k++]=job[second++];
		}
		else if(second>high)
		{
			temp1[k++]=job[first++];
		}
		else if(job[first].profit >job[second].profit )
		{
			temp1[k++]=job[first++];
		}
		else
		{
			temp1[k++]=job[second++];
		}
	}
	for(int s=0;s<k;s++)
	{
		job[low++]=temp1[s];
	}
}
void mergeSort(struct job_det *job,int start,int end)
{
	if(end>start)
	{
		int midIndex=(start+end)/2;
		mergeSort(job,start,midIndex);
		mergeSort(job,midIndex+1,end);
		merge(job,start,midIndex,end);
	}
}
int minimum(int a,int b)
{
	if(a<b)
	{
		return a; 
	}
	else
	{
		return b; 
	}
}
void jobSchedulingWithDeadlines(struct job_det *job,int size)
{
	int *sequenced_job,*slot; 
	sequenced_job=(int *)malloc((size)*sizeof(int)); 
	slot=(int *)malloc((size+1)*sizeof(int));
	int k=0;
	//1 means free,0 means booked
	for(int i=0;i<size;i++){
		slot[i]=1;
	}
	for(int i=0;i<size;i++){
		if(slot[job[i].job_dead-1]==1){
			sequenced_job[job[i].job_dead-1]=job[i].jod_id;
			slot[job[i].job_dead-1]=0;
			k++;
		}
		else{
			int search=job[i].job_dead-1;
			for(int j=search;j>0;j--){
				if(slot[j]==1){
					sequenced_job[j]=job[i].jod_id;
					slot[j]=0;
					k++;
					break;
				}
			}
		}
	}
	for(int i=0;i<k;i++){
		printf("%d ",sequenced_job[i]);
	}
}
int main()
{
	int size; 
	scanf("%d",&size); 
	struct job_det *job=(struct job_det *)malloc((size+1)*sizeof(struct job_det)); 
	for(int i=0; i<size; i++)
	{
		scanf("%d%d%d",&job[i].jod_id,&job[i].profit,&job[i].job_dead); 
	}
	mergeSort(job,0,size-1); 
	jobSchedulingWithDeadlines(job,size); 
}

