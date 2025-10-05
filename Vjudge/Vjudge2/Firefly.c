#include <stdio.h>
#include <stdlib.h>

#define MAX_H 500001

int main(){
    
    int N,H;
    scanf("%d %d", &N,&H);

    int *stalgamite = (int*)calloc(MAX_H, sizeof(int));
    int *stalcamite = (int*)calloc(MAX_H, sizeof(int));

    for (int i = 0; i < N; i++){
        int height;
        scanf("%d", &height);

        if( i%2==0){
            stalgamite[height]++;
        } else {
            stalcamite[H - height + 1]++;
        }
    }

    //int sum = 0;
    for(int i = H-1 ; i >= 0 ; i--){
        //sum += stalgamite[i];
        stalgamite[i] += stalgamite[i+1];
    }

    //sum = 0;
    for (int i = 0; i <= H; i++){
        //sum += stalcamite[i];
        stalcamite[i] += stalcamite[i-1];
    }

    int best = N;
    int count = 0;

    for(int i = 1; i<=H;i++){
        int total_obstacles = stalcamite[i] + stalgamite[i];
        if(total_obstacles < best){
            best = total_obstacles;
            count = 1;
        } else if (total_obstacles == best){
            count ++;
        }
    }
    printf("%d %d \n", best,count);

    free(stalgamite);
    free(stalcamite);

    return 0;
}