#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
struct vertex{
	int v;
	int dist;
};
struct vertex_dist_pairs{
	struct vertex *ver;
	int size;
	int maxSize;
};
void init(struct vertex_dist_pairs *v_w_p,int size,int max){
	int i=0;
	v_w_p->ver=(struct vertex *)malloc(max*sizeof(struct vertex));
	v_w_p->maxSize=max;
	for(i=0;i<max;i++){
		v_w_p->ver[i].v=i;
		v_w_p->ver[i].dist=1234;
	}
	v_w_p->size=size;
}
int leftChild(int i){
	return (2*i);
}
int rightChild(int i){
	return (2*i)+1;
}
void minHeapify(struct vertex_dist_pairs *v_w_p,int size,int position){
	int minIndex=position;
	int left=leftChild(position);
	int right=rightChild(position);
	int v=0,w=0;
	if(left<v_w_p->size && v_w_p->ver[position].dist>v_w_p->ver[left].dist){
		minIndex=left;
	}
	if(right<v_w_p->size && v_w_p->ver[minIndex].dist>v_w_p->ver[right].dist){
		minIndex=right;
	}
	if(position!=minIndex){
		w=v_w_p->ver[minIndex].dist;
		v_w_p->ver[minIndex].dist=v_w_p->ver[position].dist;
		v_w_p->ver[position].dist=w;
		v=v_w_p->ver[minIndex].v;
		v_w_p->ver[minIndex].v=v_w_p->ver[position].v;
		v_w_p->ver[position].v=v;
		minHeapify(v_w_p,size,minIndex);
	}
}
void shiftingUp(struct vertex_dist_pairs *v_w_p,int size,int pos){
	int parentIndex=(int)(pos/2);
	int currentIndex=pos;
	int v=0,w=0;
	while(currentIndex>0 && v_w_p->ver[currentIndex].dist<v_w_p->ver[parentIndex].dist){
		w=v_w_p->ver[currentIndex].dist;
		v_w_p->ver[currentIndex].dist=v_w_p->ver[parentIndex].dist;
		v_w_p->ver[parentIndex].dist=w;
		v=v_w_p->ver[currentIndex].v;
		v_w_p->ver[currentIndex].v=v_w_p->ver[parentIndex].v;
		v_w_p->ver[parentIndex].v=v;
		currentIndex=parentIndex;
		parentIndex=(int)(parentIndex/2);
	}
}
void insert(struct vertex_dist_pairs *v_w_p,int size,int distance,int vertex){
 	v_w_p->size+=1;
 	v_w_p->ver[v_w_p->size].dist=distance;
 	v_w_p->ver[v_w_p->size].v=vertex;
 	shiftingUp(v_w_p,v_w_p->size,v_w_p->size);
}
struct vertex extractMin(struct vertex_dist_pairs *v_w_p){
	struct vertex temp=(v_w_p->ver[0]);
	v_w_p->ver[0]=v_w_p->ver[v_w_p->size];
	v_w_p->size=v_w_p->size-1;
	minHeapify(v_w_p,v_w_p->size,0);
	return temp;
}
void buildminHeap(struct vertex_dist_pairs *v_w_p,int size){
	int loop=(int)((size-1)/2);
	while(loop>=0){
		minHeapify(v_w_p,size,loop);
		loop--;
	}
}
void dijkstra(struct vertex_dist_pairs *v_w_p,int adjMat[7][7],int *d,int size,int startVertex){
    int i=0,j=0;
	v_w_p->ver[startVertex].dist=0;
	d[startVertex]=0;
	while(v_w_p->size>0){
		struct vertex t=extractMin(v_w_p);
		int ver=t.v;
		int weight=t.dist;
		for(i=0;i<size;i++){
			if(adjMat[ver][i]!=0){
				if(d[i]>d[ver]+adjMat[ver][i]){
					d[i]=d[ver]+adjMat[ver][i];
					insert(v_w_p,v_w_p->size,d[i],i);
				}
			}
		}
	}
}
int main(){
	int size=0,max=50,i=0,j=0,**adjMat,*d;
	struct vertex_dist_pairs *v_w_p=(struct vertex_dist_pairs *)malloc(sizeof(struct vertex_dist_pairs));
	scanf("%d",&size);
	d=(int *)malloc(10*sizeof(int));
	adjMat=(int **)malloc((size+1)*sizeof(int *));
	for(i=0;i<=size;i++){
	    adjMat[i]=(int *)malloc((size+1)*sizeof(int));
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			scanf("%d",&adjMat[i][j]);
		}
	}
	for(i=0;i<size;i++){
		d[i]=100001;
	}
	init(v_w_p,size,max);
	buildminHeap(v_w_p,size);
	dijkstra(v_w_p,adjMat,d,size,0);
	for(i=1;i<size;i++){
		printf("%d\n",d[i]);
	}
}

// int main(){
// 	int size=0,max=50,i=0,j=0;
// 	int adjMat[7][7]={0},d[10];
// 	struct vertex_dist_pairs *v_w_p=(struct vertex_dist_pairs *)malloc(sizeof(struct vertex_dist_pairs));
// 	scanf("%d",&size);
// 	for(i=0;i<size;i++){
// 		for(j=0;j<size;j++){
// 			scanf("%d",&adjMat[i][j]);
// 		}
// 	}
// 	for(i=0;i<size;i++){
// 		d[i]=12345;
// 	}
// 	init(v_w_p,size,max);
// 	buildminHeap(v_w_p,size);
// 	dijkstra(v_w_p,adjMat,d,size,0);
// 	for(i=1;i<size;i++){
// 		printf("%d\n",d[i]);
// 	}
// }
