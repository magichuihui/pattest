#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    float n = floor(sqrt(N));
    int X, Y;
    int has_solution = 0;
    for(X=1; X<=n; X++) {
        for(Y=X; Y<=n; Y++) {
            if (X*X + Y*Y == N) {
                printf("%d %d\n", X, Y);
                has_solution = 1;
            }
        }
    }

    if(has_solution == 0) printf("No Solution\n");
}