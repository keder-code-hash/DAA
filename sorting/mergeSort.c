#include<stdio.h>
#include<stdlib.h>
void merge(int *arr,int low,int mid,int high)
{
    int size=(high-low)+1;
    int *temp=(int *)malloc(size * sizeof(int));
    int first=low,second=mid+1,k=0;
    for(int i=low;i<=high;i++)
    {
        if(first>mid)
        {
            temp[k++]=arr[second++];
        }
        else if(second>high)
        {
            temp[k++]=arr[first++];
        }
        else if(arr[first]>arr[second])
        {
            temp[k++]=arr[first++];
        }
        else{
            temp[k++]=arr[second++];
        }
    }
    for(int x=0;x<k;x++)
    {
        arr[low++]=temp[x];
    }
}
void mergeSort(int start,int end,int *arr)
{
    if(end>start)
    {
        int mid=(end+start)/2;
        mergeSort(start,mid,arr);
        mergeSort(mid+1,end,arr);
        merge(arr,start,mid,end);
    }
}
int main()
{
    int *arr=(int *)malloc(5 *sizeof(int));
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    mergeSort(0,4,arr);
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}