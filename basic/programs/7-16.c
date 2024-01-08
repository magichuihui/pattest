#include <stdio.h>

int main() {
    int start;
    scanf("%d", &start);
    // i j k分别代表百位 十位 个位数
    int i, j, k, n=0;
    for(i=start; i<start+4; i++) {
        for(j=start; j<start+4; j++) {
            if (j!=i) {
                for(k=start; k<start+4; k++) {
                    if(k!=i && k!=j) {
                        printf("%d", i*100+j*10+k);
                        n++;
                        if(n%6 == 0) {printf("\n");}
                        else {printf(" ");}
                    }
                }
            }
        }
    }
}