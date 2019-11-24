// int main(){
// 	int n = 5;
// 	int arr[] = {2,3,1,5,6};
// 	construct_req(arr,n);
// 	printf("Minimum in range %d to %d = %d\n",2,3,range_min(0,n-1,2,3,0));
// 	update_req(10,2,n);
// 	printf("Minimum in range %d to %d = %d\n",2,3,range_min(0,n-1,2,3,0));
// 	return 0;
// }
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include "segment_tree_cpu.h"
int construct_tree_recur(int *arr,int start,int end,int st_index){
	if(start==end){
		st[st_index]=arr[start];
	}else{
		int mid = start + (end-start)/2;
		st[st_index] =MIN(construct_tree_recur(arr,start,mid,2*st_index+1),construct_tree_recur(arr,mid+1,end,2*st_index+2));
	}
	return st[st_index];
}
void construct_req_recur(int *arr,int n){
	int h,num_nodes;
	h = (int)ceil(log10(n)/log10(2));
	num_nodes = 2*((int)pow(2,h))-1;
	st = (int*)calloc(num_nodes,sizeof(int));
	assert(st);
	construct_tree_recur(arr,0,n-1,0);
}
int range_min_recur(int start,int end,int q_start,int q_end,int st_index){
	int mid;
	if(start>=q_start&&end<=q_end){
		return st[st_index];
	}
	if(start>q_end||end<q_start){
		return INT_MAX;
	}
	mid = start + (end-start)/2;
	return MIN(range_min_recur(start,mid,q_start,q_end,2*st_index+1),range_min_recur(mid+1,end,q_start,q_end,2*st_index+2));
}
int update_recur(int start,int end,int val,int index,int st_index){
	int mid;
	if(start==end && index==start){
		st[st_index]=val;
	}else if(start==end){
		return st[st_index];
	}else{
		mid = start + (int)(end-start)/2;
		st[st_index] = MIN(update_recur(start,mid,val,index,st_index*2+1),update_recur(mid+1,end,val,index,2*st_index+2));
	}
	return st[st_index];
}
void update_req_recur(int val,int index,int n){
	update_recur(0,n-1,val,index,0);
}
