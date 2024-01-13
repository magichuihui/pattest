#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct mooncake {
    double inventory;
    double total_price;
    double rates;
} mooncake;

double select_sort(mooncake *m[], int demands, int size);

int main() {
    int N;
    int demands;
    scanf("%d %d", &N, &demands);

    mooncake *m[MAX_SIZE];
    int i;
    double inventory, total_price;
    for (i=0;i<N;i++) {
        scanf("%lf", &inventory);
        mooncake *temp = (mooncake *) malloc(sizeof(mooncake *));
        temp->inventory = inventory;
        m[i] = temp;
    }

    for (i=0;i<N;i++) {
        scanf("%lf", &total_price);
        m[i]->total_price = total_price;
        m[i]->rates = total_price / m[i]->inventory;
    }

    double res = select_sort(m, demands, N);

    printf("%.2lf\n", res);

    // for (i=0;i<N;i++) {
    //     printf("%lf %lf\n", m[i]->inventory, m[i]->rates);
    // }
}

double select_sort(mooncake *m[], int demands, int size) {
    int i, j, t;
    double sum_inventory=0.0, total_price=0.0;
    mooncake *temp;
    for(i=size-1;i>=0;i--) {
        t=i;
        for(j=0;j<i;j++) {
            if (m[j]->rates > m[t]->rates) t=j;
        }

        if (t!=i) {
            temp = m[t];
            m[t] = m[i];
            m[i] = temp;
        }

        sum_inventory += m[i]->inventory;
        if (sum_inventory >= demands) break;
        total_price += m[i]->total_price;

    }
    if (sum_inventory > demands) return total_price + (m[i]->inventory-sum_inventory+demands) * m[i]->rates;
    if (i<0) return total_price;
    return total_price+m[i]->total_price;
}