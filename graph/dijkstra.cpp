#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
struct vertex{
	int v;
	int weight;
};
struct vertex_weight_pairs{
	struct vertex *ver;
	int size;
};
void init(struct vertex_weight_pairs *v_w_p,int size){
	v_w_p->ver=(struct vertex *)malloc(size*sizeof(struct vertex));
	for(int i=0;i<size;i++){
		v_w_p->ver[i].v=i;
		v_w_p->ver[i].weight=INT_MAX;
	}
	v_w_p->size=size;
	v_w_p->ver[3].weight=11;
}
int leftChild(int i){
	return (2*i);
}
int rightChild(int i){
	return (2*i)+1;
}
void minHeapify(struct vertex_weight_pairs *v_w_p,int size,int position){
	int minIndex=0;
	int left=leftChild(position);
	if(left<size && v_w_p->ver[position].weight>v_w_p->ver[left].weight){
		minIndex=left;
	}
	int right=rightChild(position);
	if(right<size && v_w_p->ver[minIndex].weight>v_w_p->ver[right].weight){
		minIndex=right;
	}
	if(minIndex!=position){
		printf("hiiii ");
		int w=v_w_p->ver[minIndex].weight;
		v_w_p->ver[minIndex].weight=v_w_p->ver[position].weight;
		v_w_p->ver[position].weight=w;
		int v=v_w_p->ver[minIndex].v;
		v_w_p->ver[minIndex].v=v_w_p->ver[position].v;
		v_w_p->ver[position].v=v;
		minHeapify(v_w_p,size,minIndex);
	}
}
void buildminHeap(struct vertex_weight_pairs *v_w_p,int size){
	int loop=(int)(size-1/2);
	while(loop>=0){
		minHeapify(v_w_p,size,loop);
		loop--;
	}
}
int main(){
	int size=8;
	struct vertex_weight_pairs *v_w_p=(struct vertex_weight_pairs *)malloc(sizeof(struct vertex_weight_pairs));
	init(v_w_p,size);
	buildminHeap(v_w_p,size);
	for(int i=0;i<size;i++){
		printf("%d %d ",v_w_p->ver[i].v,v_w_p->ver[i].weight);
		printf("\n");
	}
}
