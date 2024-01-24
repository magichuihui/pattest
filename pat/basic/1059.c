#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10000

int prime(int x);

int main() {
    int rank[MAX_SIZE];
    int N, K;
    scanf("%d", &N);
    int i, id;
    for (i=0;i<MAX_SIZE;i++) rank[i]=0;
    for (i=0;i<N;i++) {
        scanf("%d", &id);
        rank[id]=i+1;
    }

    scanf("%d", &K);
    for (i=0;i<K;i++) {
        scanf("%d", &id);
        if (rank[id]==1) {
            rank[id]=-1;
            printf("%04d: %s\n", id, "Mystery Award");
        } else if (rank[id] == -1) {
            printf("%04d: %s\n", id, "Checked");
        } else if (rank[id]==0) {
            printf("%04d: %s\n", id, "Are you kidding?");
        } else if (prime(rank[id])) {
            rank[id]=-1;
            printf("%04d: %s\n", id, "Minion");
        } else {
            rank[id]=-1;
            printf("%04d: %s\n", id, "Chocolate"); 
        }
    }
}

int prime(int x) {
    int n = (int) ceil(sqrt(x));
    int i;
    for (i=2;i<=n;i++) {
        if (x%i == 0) return 0;
    }

    return 1;
}