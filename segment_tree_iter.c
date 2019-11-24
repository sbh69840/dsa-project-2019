#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include "segment_tree_iter.h"
void construct_tree_iter(int *arr,int n){
	st1 = (int*)calloc(2*n,sizeof(int));
	assert(st1);
	int i;
	for(i=0;i<n;i++){
		st1[n+i] = arr[i];
	}
	for(i=n-1;i>=1;i--){
		st1[i] = MIN(st1[2*i],st1[2*i+1]);
	}
}
void update_iter(int val,int index,int n){
	st1[n+index]=val;
	int pos=n+index;
	while(pos>1){
		pos>>=1;
		st1[pos]=MIN(st1[2*pos],st1[2*pos+1]);	
	}
}
int range_min_iter(int l,int r,int n){
	l+=n;
	r+=n;
	int min = INT_MAX;
	while(l<r){
		if(l&1){
			min = MIN(min,st1[l]);
			l++;
		}
		if(r&1){
			r--;
			min = MIN(min,st1[r]);
		}
		l/=2;
		r/=2;
	}
	return min;
}
