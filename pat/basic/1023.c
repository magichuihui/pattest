#include <stdio.h>

int main(void) {
    int counter[10];
    int i;
    for (i=0;i<10;i++) {
        scanf("%d", &counter[i]);
    }

    // 如果数字里包含0， 首位需要找到最小的非零数
    if (counter[0]>0) {
        for (i=1;i<10;i++) {
            if (counter[i]>0) {
                printf("%d", i);
                counter[i]--;
                break;
            }
        }
        while((counter[0]--) > 0) printf("0");
    }

    for (i=1;i<10;i++) {
        while(counter[i]-- > 0) printf("%d", i);
    }
}