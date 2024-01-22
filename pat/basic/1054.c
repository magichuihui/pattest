#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);
    
    char **numbers = (char **) malloc(N * sizeof(char *));

    int i;
    for (i=0;i<N;i++) {
        numbers[i] = (char *) malloc(12 * sizeof(char));
        scanf("%s", numbers[i]);
    }

    for (i=0;i<N;i++) {
        printf("%s\n", numbers[i]);
    }
}