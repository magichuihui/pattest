#include <stdio.h>

void sort(int temp[], int num);

int main() {
    int N;
    scanf("%d", &N);

    int temp[4];
    int high, low, diff=N;
    while (diff!=0) {
        sort(temp, diff);
        high = temp[3] * 1000 + temp[2] * 100 + temp[1] * 10 + temp[0];
        low = temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];
        diff = high - low;
        printf("%04d - %04d = %04d\n", high, low, diff);
        if (diff==6174) break;
    }
}

void sort(int temp[], int num) {
    int i, j, k, remainder;
    for (i=0;i<4;i++) {
        remainder = num % 10;
        for (j=i-1;j>=0;j--) {
            if (temp[j] < remainder) break;
        }

        for (k=i;k>j+1;k--) {
            temp[k] = temp[k-1];
        }
        temp[j+1] = remainder;
        num /= 10;
    }
}