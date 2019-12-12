#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MIN(a,b) a<b?a:b
#define INT_MAX 214783648
int *st;
int construct_tree(int *arr,int start,int end,int st_index);
void construct_req(int *arr,int n);
int update(int start,int end,int st_index,int val,int index);
void update_req(int val,int index,int n);
int range_min(int start,int end,int q_start,int q_end,int st_index);
int main(){
	int n,opt,l,r,v,ind;
    printf("Enter number of elements\n");
    scanf("%d",&n);
	int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d\n",i);
        scanf("%d",&arr[i]);
    }
    construct_req(arr,n);
    while(1){
        printf("Select an option:\n1)Range min\n2)Update\n3)Exit");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("Enter l and r values\n");
                scanf("%d%d",&l,&r);
                printf("Minimum in range %d to %d = %d\n\n",l,r,range_min(0,n-1,l,r,0));
                break;
            case 2:
                printf("Enter index and value to update\n");
                scanf("%d%d",&ind,&v);
                update_req(v,ind,n);
                printf("\n\n");
                break;
            case 3:
                printf("\n");
                return 0;
        }
    }
	return 0;
}
int construct_tree(int *arr,int start,int end,int st_index){
	if(start==end){
		st[st_index]=arr[start];
	}else{
		int mid = start + (end-start)/2;
		st[st_index] =MIN(construct_tree(arr,start,mid,2*st_index+1),construct_tree(arr,mid+1,end,2*st_index+2));
	}
	return st[st_index];
}
void construct_req(int *arr,int n){
	int h,num_nodes;
	h = (int)ceil(log10(n)/log10(2));
	num_nodes = 2*((int)pow(2,h))-1;
	st = (int*)calloc(num_nodes,sizeof(int));
	construct_tree(arr,0,n-1,0);
}
int range_min(int start,int end,int q_start,int q_end,int st_index){
	int mid;
	if(start>=q_start&&end<=q_end){
		return st[st_index];
	}
	if(start>q_end||end<q_start){
		return INT_MAX;
	}
	mid = start + (end-start)/2;
	return MIN(range_min(start,mid,q_start,q_end,2*st_index+1),range_min(mid+1,end,q_start,q_end,2*st_index+2));
}
int update(int start,int end,int val,int index,int st_index){
	int mid;
	if(start==end && index==start){
		st[st_index]=val;
	}else if(start==end){
		return st[st_index];
	}else{
		mid = start + (int)(end-start)/2;
		st[st_index] = MIN(update(start,mid,val,index,st_index*2+1),update(mid+1,end,val,index,2*st_index+2));
	}
	return st[st_index];
}
void update_req(int val,int index,int n){
	update(0,n-1,val,index,0);
}
