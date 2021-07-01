#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct minHeapNode{
	int vertex;
	int weight;
};
struct minHeap{
	struct minHeapNode **heap;
	int *heapPos;
	int size;
	int maxSize;
};
struct minHeapNode *createMinHeapNode(int w,int v){
	struct minHeapNode *node=(struct minHeapNode*)malloc(sizeof(minHeapNode));
	node->vertex=v;
	node->weight=w;
	return node;
};
struct minHeap *createMinHeap(int maxSize){
	struct minHeap *heapNode=(struct minHeap *)malloc(sizeof(struct minHeap));
	heapNode->heap=(struct minHeapNode**)malloc(maxSize*sizeof(struct minHeapNode*));
	heapNode->heapPos=(int *)malloc(maxSize*sizeof(int));
	heapNode->maxSize=maxSize;
	heapNode->size=0;
	return heapNode;
}
void swap(struct minHeapNode **a,struct minHeapNode **b){
	struct minHeapNode* temp=*a;
	*a=*b;
	*b=temp;
}
int rightChild(int i){
	return (2*i)+1;
}
int leftChild(int i){
	return (2*i);
}
void minHeapify(struct minHeap *mHeap,int position){
	int minIndex=position;
	int left=leftChild(position);
	int right=rightChild(position);
	if(left<mHeap->size && mHeap->heap[minIndex]->weight > mHeap->heap[left]->weight){
		minIndex=left;
	}
	if(right<mHeap->size && mHeap->heap[minIndex]->weight > mHeap->heap[right]->weight){
		minIndex=right;
	}
	if(minIndex!=position){
		struct minHeapNode* minNode=mHeap->heap[minIndex];
		struct minHeapNode* node=mHeap->heap[position];
		mHeap->heapPos[minNode->vertex]=position;
		mHeap->heapPos[node->vertex]=minIndex;
		swap(&mHeap->heap[minIndex],&mHeap->heap[position]);
		minHeapify(mHeap,minIndex);
	}
}
struct minHeapNode *extractMinHeap(struct minHeap *mHeap){
	if(mHeap->size<0){
		return NULL;
	}
	struct minHeapNode *extractNode=mHeap->heap[0];
	struct minHeapNode *last=mHeap->heap[mHeap->size-1];
	mHeap->heapPos[extractNode->vertex]=mHeap->size-1;
	mHeap->heapPos[last->vertex]=0;
	mHeap->heap[0]=last;
	mHeap->size--;
	minHeapify(mHeap,0);
	return extractNode;
}
void decreaseKey(struct minHeap *mHeap,int ver,int wei){
	int index=mHeap->heapPos[ver];
	mHeap->heap[index]->weight=wei;
	while(index && mHeap->heap[index]->weight < mHeap->heap[(index-1)/2]->weight){
		mHeap->heapPos[mHeap->heap[index]->vertex]=(index-1)/2;
		mHeap->heapPos[mHeap->heap[(index-1)/2]->vertex]=index;
		swap(&mHeap->heap[index],&mHeap->heap[(index-1)/2]);
		index=(index-1)/2;
	}
}
int belongsTo(struct minHeap *mHeap,int vertex){
	if(mHeap->heapPos[vertex] < mHeap->size){
		return 1;
	}
	return 0;
}
int prims(struct minHeap *mHeap,int **adjMat,int *weights,int vertex_no){
	int weight=0,startingVertex=0,i=0;
	weights[0]=0;
	mHeap->heapPos[0]=0;
	mHeap->heap[0]=createMinHeapNode(0,0);
	while(mHeap->size >0){
		struct minHeapNode *temp=extractMinHeap(mHeap);
		startingVertex=temp->vertex;
		for(i=0;i<vertex_no;i++){
			if(adjMat[startingVertex][i]!=0 && belongsTo(mHeap,i) && adjMat[startingVertex][i]<weights[i]){
					weights[i]=adjMat[startingVertex][i];
					decreaseKey(mHeap,i,weights[i]);
				}
		}
	}
	for(i=1;i<vertex_no;i++){
		weight+=weights[i];
	}
	return weight;
}
int main(){
	int vertex_no=0,**adjMat,*weights,i=0,j=0;
	scanf("%d",&vertex_no);
	struct minHeap *mHeap=createMinHeap(vertex_no);
	weights=(int *)malloc(vertex_no*sizeof(int));
	for(i=0;i<vertex_no;i++){
		weights[i]=INT_MAX;
	}
	for(i=1;i<vertex_no;i++){
		mHeap->heap[i]=createMinHeapNode(INT_MAX,i);
		mHeap->heapPos[i]=i;
	}
	mHeap->size=vertex_no;
	adjMat=(int **)malloc(vertex_no*sizeof(int *));
	for(i=0;i<vertex_no;i++){
		adjMat[i]=(int *)malloc(vertex_no*sizeof(int));
	}
	for(i=0;i<vertex_no;i++){
		for(j=0;j<vertex_no;j++){
			scanf("%d",&adjMat[i][j]);
		}
	}
	printf("%d ",prims(mHeap,adjMat,weights,vertex_no));
}
//2 3 6 5..
