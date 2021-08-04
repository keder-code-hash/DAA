#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
/*
3 1 9 52= 

*/
int partition(int *arr,int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int k=low;k<high;k++)
    {
        if(arr[k]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[k]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void quickSort(int *arr,int start,int end)
{
    if(end>start)
    {
        int part=partition(arr,start,end);
        quickSort(arr,start,part-1);
        quickSort(arr,part+1,end);
    }
}
void main()
{
    int *arr=(int *)malloc(5 *sizeof(int));
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,4);
    // partition(arr,0,4);
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
}