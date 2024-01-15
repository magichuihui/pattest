#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100000

int binary_search(int numbers[], int N, double mp);

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
        if (numbers[mid]==(int) floor(mp)) {
            while (numbers[mid+1] == numbers[mid]) mid++;
            return mid;
        } else if (mp>numbers[mid]) {
            low = mid+1;
        } else {
            high = mid - 1;
        }

    }

    while (low > 0 && numbers[low] > mp) low--;
    return low;
}