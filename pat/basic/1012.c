#include <stdio.h>

#define MAX_SIZE 1001
 
void print_N();

int main() {
    int numbers[MAX_SIZE];
    int i = 0;
    do {
        scanf("%d", &numbers[i++]);
    } while (getchar() != '\n' && i <= MAX_SIZE);

    union result {
        int i;
        double d;
    } A[5];
    for (i=0;i<5;i++) {
        if (i==3) {
            A[i].d =0.0;
        } else {
            A[i].i = 0;
        }
    }

    int count[5];
    for(i=0;i<5;i++) count[i]=0;
    int sign = 1;

    for (i=1;i<=numbers[0];i++) {
        // A1
        if (numbers[i] % 10 == 0) {
            A[0].i += numbers[i];
            count[0]++;
        // A2
        } else if (numbers[i] % 5 == 1) {
            A[1].i += sign * numbers[i];
            sign = -1 * sign;
            count[1]++;
        } else if (numbers[i] % 5 == 2) {
            A[2].i++;
            count[2]++;
        } else if (numbers[i] % 5 == 3) {
            A[3].d += numbers[i];
            count[3]++;
        } else if (numbers[i] % 5 == 4) {
            if (numbers[i] > A[4].i) A[4].i = numbers[i];
            count[4]++;
        }
    }

    for (i=0;i<5;i++) {
        if (count[i] > 0) {
            if (i==3) {
                printf("%.1lf", A[3].d / count[3]);
            } else {
                printf("%d",A[i].i);
            }
        } else {
            print_N();
        }

        if (i!=4) printf(" ");
    }
}

void print_N() {
    printf("N");
}