#include <stdio.h>

int main (){

    int K;
    scanf("%d", &K);
    for (int i =1; i < K +1; i++){
        int numbers [21];
        int stepsBack = 0;
        scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
          &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5], 
          &numbers[6], &numbers[7], &numbers[8], &numbers[9], &numbers[10], &numbers[11],
          &numbers[12], &numbers[13], &numbers[14], &numbers[15], &numbers[16], &numbers[17],
          &numbers[18], &numbers[19], &numbers[20]);
        
    for (int i = 1; i < 21; i++){
        int key = numbers[i];
        //printf("%d ", numbers[i]);
        int j = i - 1;
        while (j>0 && numbers[j] > key){
            numbers[j + 1] = numbers[j];
            j -= 1;
            stepsBack+=1;
        }
        numbers[j+1] = key;
    }

    printf("%d %d \n", i, stepsBack);

    }

    return 0;
}