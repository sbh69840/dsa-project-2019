#ifndef __TREE_ITER__
#define __TREE_ITER__

#define MIN(a,b) a<b?a:b
#define INT_MAX 214783648
int *st1;
void construct_tree_iter(int *arr,int n);
void update_iter(int val,int index,int n);
int range_min_iter(int l,int r,int n);

#endif