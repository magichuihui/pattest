#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

int binary_search(int numbers[], int N, double mp);

int cmp(const void * a, const void * b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    int N, p;
    scanf("%d %d", &N, &p);
    int i, j, k, numbers[MAX_SIZE];

    int temp;
    for (i=0;i<N;i++) {
        scanf("%d", numbers+i);
    }

    qsort(numbers, N, sizeof(int), cmp);
    //for (i=0;i<N;i++) printf("%d\n", numbers[i]);

    int max=0, count, enough=0;
    double mp;
    for (i=0;i<N;i++) {
        if (enough) break;
        mp = (double) numbers[i] * p;
        if (mp > numbers[N-1]) enough=1;
        count = binary_search(numbers, N, mp) - i + 1;

        if (count>max) max = count;
    }

    printf("%d\n", max);
}

int binary_search(int numbers[], int N, double mp) {
    int low=0, high=N-1, mid;
    while (low < high) {
        mid=(high+low)/2;
        if (numbers[mid]==mp) {
            while (numbers[mid+1] == numbers[mid]) mid++;
            return mid;
        } else if (mp>numbers[mid]) {
            while(mid < N-1 && numbers[mid+1] == numbers[mid]) mid++;
            if (mid==N-1) return N-1;
            low = mid+1;
        } else {
            while(mid > 0 && numbers[mid-1] == numbers[mid]) mid--;
            if (mid==0) return 0;
            high = mid - 1;
        }

    }

    while (low > 0 && numbers[low] > mp) low--;
    return low;
}