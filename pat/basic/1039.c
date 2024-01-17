#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1001

int hash(char c);

int main(void) {
    int counter[62];
    char sell[MAX_SIZE], require[MAX_SIZE];

    scanf("%s", &sell);
    scanf("%s", &require);

    int length_s = strlen(sell), length_r = strlen(require);
    int i;

    for (i=0;i<62;i++) counter[i]=0;

    // counter数组记录需要的颜色个数
    for (i=0;i<length_r;i++) counter[hash(require[i])]++;

    // 计算尚未满足的颜色
    for (i=0;i<length_s;i++) counter[hash(sell[i])]--;

    int lack=0;
    for (i=0;i<62;i++) {
        if (counter[i]>0) lack += counter[i];
    }

    if (lack>0) {
        printf("No %d\n", lack);
    } else {
        printf("Yes %d\n", length_s-length_r);
    }

}

// 把需要的颜色映射到数组counter
int hash(char c) {
    if (c<='9' && c>='0') return c - '0';
    if (c<='z' && c>='a') return c - 'a' + 10;
    if (c<='Z' && c>='A') return c - 'A' + 36;

    return -1;
}