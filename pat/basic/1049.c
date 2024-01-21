#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);
    
    int i;
    // not sure whether minGW support long double or not,
    // but it works on pat website's clang and gcc environment.
    long double number, sum=0;
    for (i=0;i<N;i++) {
        scanf("%Lf", &number);
        sum += number * (N-i) * (i+1);
    }

    printf("%.2Lf\n", sum);

}