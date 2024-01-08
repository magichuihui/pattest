#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define LENGTH 11

int main() {
    char arr[MAX_SIZE][LENGTH];
    char temp[LENGTH];

    int K, N;
    scanf("%d %d", &N, &K);
    
    int i, time=0;
    for(i=0;i<N;i++) {
        scanf("%s", arr[i]);
    }
 

    while(time < K) {
        for(i=0;i<N-time-1;i++) {
            if(strcmp(arr[i], arr[i+1]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
            }
        }
        time++;
    }

    for(i=0;i<N;i++) {
        printf("%s\n", arr[i]);
    }
}