#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

int merge_sort(int arr[], int backup[], int intermediate[], int length);
void insertion_sort(int intermediate[], int length);
void insertion(int original[], int intermediate[], int length);

int main(void) {
    int N;
    int original[MAX_SIZE], intermediate[MAX_SIZE], backup[MAX_SIZE], back2[MAX_SIZE];
    scanf("%d", &N);

    int i;
    for (i=0;i<N;i++) {
        scanf("%d", &original[i]);
    }

    for (i=0;i<N;i++) {
        scanf("%d", &intermediate[i]);
    }

    for (i=0;i<N;i++) back2[i] = original[i];

    if (merge_sort(original, backup, intermediate, N)) return 0;

    // printf("Insertion Sort\n");
    // insertion_sort(intermediate, N);

    insertion(back2, intermediate, N);

}

int merge_sort(int arr[], int backup[], int intermediate[], int length) {
    int h=2, i, j, a, b;
    int match = 0;
    while (h/2 <= length) {
        for(i=0;i<length;i+=h) {
            a = i;
            b = i+h/2;
            j = i;
            while (j<length && j<i+h) {
                while (a<i+h/2 && a<length && arr[a] < arr[b]) backup[j++] = arr[a++];
                while (b<i+h && b<length && arr[a] >= arr[b]) backup[j++] = arr[b++];

                if (a>=i+h/2) backup[j++] = arr[b++];
                if (b>=i+h || b>= length) backup[j++] = arr[a++];

            }
        }

        // 上一轮跟中间结果匹配
        if (match) {
            printf("%s\n", "Merge Sort");
            for (j=0;j<length;j++) {
                printf("%d", backup[j]);
                if (j!=length-1) printf(" ");
            }
            printf("\n");
            return 1;
        }

        j = 0;
        while (j<length && backup[j] == intermediate[j]) j++;
        if (j==length) match=1;

        for (i=0;i<length;i++) arr[i] = backup[i];

        h *= 2;
    }

    return 0;
}

void insertion_sort(int intermediate[], int length) {
    int i=0, j, k, temp;
    while (i<length-1 && intermediate[i] < intermediate[i+1]) i++;

    // 还没完全排序
    if (i<length-1) {
        j=i;
        while (j>=0) {
            if (intermediate[j] <= intermediate[i+1]) break;
            j--;
        }

        temp = intermediate[i+1];
        for (k=i;k>j;k--) intermediate[k+1] = intermediate[k];

        intermediate[j+1] = temp;
    }

    for(i=0;i<length;i++) {
        printf("%d", intermediate[i]);
        if (i!=length-1) printf(" ");
    }

    printf("\n");

}

void insertion(int original[], int intermediate[], int length) {
    int i, j, k, temp;
    int match = 0;
    for (i=1;i<length;i++) {
        j=i-1;
        temp = original[i];
        while(j>=0 && original[j] > temp) {
            original[j+1] = original[j];
            j--;
        }

        original[j+1] = temp;

        // for (k=0;k<length;k++) printf("%d ", original[k]);

        if (match) {
            printf("%s\n", "Insertion Sort");
            for (j=0;j<length;j++) {
                printf("%d", original[j]);
                if (j!=length-1) printf(" ");
            }
            printf("\n");
            break;
        }

        j = 0;
        while (j<length && original[j] == intermediate[j]) j++;
        if (j==length) match=1;
    }

}