#ifndef __TREE_RECUR__
#define __TREE_RECUR__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#define MIN(a,b) a<b?a:b
#define INT_MAX 214783648
int *st;
int construct_tree_recur(int *arr,int start,int end,int st_index);
void construct_req_recur(int *arr,int n);
int update_recur(int start,int end,int st_index,int val,int index);
void update_req_recur(int val,int index,int n);
int range_min_recur(int start,int end,int q_start,int q_end,int st_index);

#endif