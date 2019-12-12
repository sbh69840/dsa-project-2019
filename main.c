#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<assert.h>
#include "segment_tree_cpu.h"
#include "segment_tree_iter.h"
#define t 6

int n_values[] = {10,100,1000,10000,100000,1000000};
double cpu_recur_time[t];
double cpu_iter_time[t];
double cpu_brute_force[t];
void csv(char filename[]){
	FILE *fp;
	fp = fopen(filename,"w+");
	fprintf(fp,"No. Elements,CPU brute force,CPU iterative,CPU recursive");
	for(int i=0;i<t;i++){
        fprintf(fp,"\n%d",n_values[i]);
        fprintf(fp,",%f",cpu_brute_force[i]);
		fprintf(fp,",%f",cpu_iter_time[i]);
		fprintf(fp,",%f",cpu_recur_time[i]);
	}
	fclose(fp);
	printf("\n %s file created\n",filename);
}
int main(){
    int N,*arr;
    for(int i=0;i<t;i++){
        N = n_values[i];
        arr = (int*)calloc(N,sizeof(int));
        assert(arr);
        for(int i=0;i<N;i++){
            arr[i] = rand()%1000000000;
        }
        construct_tree_iter(arr,N);
        construct_req_recur(arr,N);
        clock_t t1;
        double cpu_recur = 0.0;
        for(int j=0;j<10;j++){
            t1 = clock();
            for(int i=0;i<1;i++){
                int l = 0;
                int r = (int)(N/2)+(rand()%(N/2));
                range_min_recur(0,N-1,l,r,0);
            }
            t1 = clock()-t1;
            cpu_recur+= ((double)t1)/CLOCKS_PER_SEC;

        }
        cpu_recur*=100;
        double cpu_iter = 0.0;
        for(int j=0;j<10;j++){
            t1 = clock();
            for(int i=0;i<1;i++){
                int l = 0;
                int r = (int)(N/2)+(rand()%(N/2));
                range_min_iter(l,r+1,N);
            }
            t1 = clock()-t1;
            cpu_iter+= ((double)t1)/CLOCKS_PER_SEC;

        }
        cpu_iter*=100;
        double cpu_brute = 0.0;
        for(int j=0;j<10;j++){
            t1 = clock();
            for(int i=0;i<1;i++){
                int l = 0;
                int r = (int)(N/2)+(rand()%(N/2));
                int val = INT_MAX;
                for(int k=l;k<=r;k++){
                    if(arr[k]<val){
                        val = arr[k];
                    }
                }
            }
            t1 = clock()-t1;
            cpu_brute+= ((double)t1)/CLOCKS_PER_SEC;

        }
        cpu_brute*=100;
        cpu_iter_time[i] = cpu_iter;
        cpu_brute_force[i] = cpu_brute;
        cpu_recur_time[i] = cpu_recur;
        printf("%.5lf %.5lf %.5lf\n",cpu_brute,cpu_iter,cpu_recur);
    }
    csv("SEARCH.csv");
    free(arr);
    free(st);
    free(st1);
}	
