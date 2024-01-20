#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100010

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) < (b) ? (a) : (b)

int comfunc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(void) {
    int N;
    int number[MAX_SIZE], max_left[MAX_SIZE], min_right[MAX_SIZE];
    scanf ("%d", &N);
    
    int i, count=0;

    for (i=0;i<N;i++) {
        scanf("%d", &number[i]);
        max_left[i] = 0;
        min_right[i] = 1E9 + 1;
    }
    for (i=1;i<N;i++) max_left[i] = max(max_left[i-1], number[i-1]);
    for (i=N-2;i>=0;i--) min_right[i] = min(min_right[i+1], number[i+1]);
 
    for (i=0;i<N;i++) if (number[i] > max_left[i] && number[i] < min_right[i]) count++;
    printf("%d\n", count);

    for (i=0;i<N;i++) {
        if (number[i] > max_left[i] && number[i] < min_right[i]) {
            printf("%d", number[i]);
            if (count--!=1) printf(" ");
        }
    }
    printf("\n");
   
}
