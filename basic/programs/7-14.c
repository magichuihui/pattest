#include <stdio.h>

int main() {
    int start, end, i=0, sum=0;
    scanf("%d %d", &start, &end);

    while (start <= end) {
        printf("%5d", start);
        i++;
        sum += start++;
        if (start > end || i % 5 == 0) printf("\n");
    }

    printf("Sum = %d\n", sum);
}