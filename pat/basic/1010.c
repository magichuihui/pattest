#include <stdio.h>

#define MAX_SIZE 2000

int main() {
    int numbers[MAX_SIZE];

    int count = 0;
 
    // Perform a do-while loop
    do {
        scanf("%d", &numbers[count++]);
    } while (getchar() != '\n' && count < 2000);

    int i;
    // for (i=0;i<count;i++) printf("%d\n", numbers[i]);

    int coefficient;
    int non_zero = 0;
    int first=1;
    for (i=0;i<count-1;i+=2) {
        coefficient = numbers[i] * numbers[i+1];
        if (coefficient) {
            non_zero = 1;
            if (!first) printf(" ");
            printf("%d", coefficient);
            printf(" %d", numbers[i+1] == 0 ? 0 : numbers[i+1] - 1);
            first = 0;
        }
    }

    // 导数为零
    if (!non_zero) printf("0 0");
}