#include <stdio.h>
#include <string.h>


int main(){

    int n ;
    scanf("%d", &n);
    while (n != 0 ){
        //2D array to store names
        char names[n][21];
        // read in names
        for (int i = 0; i < n; i++){
            scanf("%s", names[i]);
        }

        for(int i = 1; i < n ; i++){
            char current_name[21];
            strcpy(current_name, names[i]);
            int j = i -1;
            while( j >= 0 && (strncmp(names[j], current_name, 2) > 0)){
                strcpy(names[j+1], names[j]);
                j --;
            }
            strcpy(names[j+1], current_name);
        
    }
    for(int i = 0; i < n; i++){
            printf("%s \n",names[i]);
        }
    printf("\n");

    scanf("%d", &n);
    }
    return 0;
}