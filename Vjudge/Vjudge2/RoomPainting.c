#include <stdio.h>
#include <stdlib.h>

#define maxInput 100001

int compare(const void*a, const void *b){
    return (*(int*)a - *(int*)b);
}

int find_smallest_can(int cans[], int n, int requiered_paint){
    int left = 0;
    int right = n-1;
    while(left < right){
        int mid = (left + right)/2 ;
        if(cans[mid] >= requiered_paint){
            right = mid;
        } else{
            left = mid +1;
        }
    }
    return cans[left];
}   

int main(){

    int n,m;
    scanf("%d %d", &n,&m);

    int *paintCans = (int*)malloc(n*sizeof(int));

    // read input 
    for (int i = 0; i < n ;i++){
        scanf("%d", &paintCans[i]);
    }

    //sort fror binary search
    qsort(paintCans,n,sizeof(int),compare);


    int total_difference = 0;
    for(int i = 0; i< m; i++){
        int requiered_paint;
        scanf("%d", &requiered_paint);

        //smallest can aviable 
        int smallest_can = find_smallest_can(paintCans,n,requiered_paint);

        total_difference += smallest_can - requiered_paint;
    }

    printf("%d", total_difference);

    free(paintCans);
    return 0;
}