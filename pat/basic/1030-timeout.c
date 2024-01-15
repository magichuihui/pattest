#include <stdio.h>

#define MAX_SIZE 100000

int main(void) {
    int N, p;
    scanf("%d %d", &N, &p);
    int i, j, k, numbers[MAX_SIZE];

    int temp;
    for (i=0;i<N;i++) {
        scanf("%d", &temp);
        j = i-1;
        while(j>=0 && numbers[j]>temp) j--;
        for (k=i;k>j+1;k--) numbers[k] = numbers[k-1];
        numbers[j+1] = temp;
    }

    for (i=0;i<N;i++) printf("%d\n", numbers[i]);

    int max=0, count;
    double mp;
    for (i=0;i<N;i++) {
        mp = (double) numbers[i] * p;
        count = 0;
        for (j=0;j<N;j++) {
            if (numbers[j] >= numbers[i] && numbers[j] <= mp) count++;
        }
        if (count>max) max = count;
    }

    printf("%d\n", max);

}

int binary_search(int numbers[], int N, double mp) {
    int low=0, high=N-1, mid;
    while (low < high) {
        mid=(high+low)/2;
        if (mp==numbers[mid]) {
            break;
        } else if (mp>numbers[mid]) {
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}