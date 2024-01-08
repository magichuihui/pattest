#include <stdio.h>
#include <string.h>

#define MAX_SIZE 82

int main() {
    char s1[MAX_SIZE];
    char s2[MAX_SIZE];
    int deleted[MAX_SIZE];
    fgets(s1, MAX_SIZE, stdin);
    fgets(s2, MAX_SIZE, stdin);

    int l1, l2;
    l1 = strlen(s1)-1;
    l2 = strlen(s2)-1;

    // 用于模式匹配的2个指针
    int i, j, k, m;

    // 本趟匹配是否匹配到
    int matched = 1;
    for(i=0;i<l1;i++) deleted[i]=0;

    while(matched) {
        matched = 0;
        i=0;j=0;
        while(i<l1) {
            // 母串已经标记删除
            if(deleted[i]) {
                i++;
                continue;
            }

            // 母串i 跟子串j 匹配
            if(s1[i] == s2[j]) {
                // 找到子串的匹配了
                if (j==l2-1) {
                    // 设置deleted标志
                    k=0; 
                    m=i;
                    matched = 1;
                    while (k<l2) {
                        if (deleted[m] == 0) {
                            deleted[m] = 1;
                            k++;
                        }
                        m--;
                    }
                    j=0;
                    i++;
                } else {
                    i++;
                    j++;
                }
                
            // 母串i 跟子串j 不匹配
            } else {
                if (j>0) {
                    i=i-j+1;
                    j=0;
                } else {
                    i++;
                }
            }

        }
    }

    for(i=0;i<l1;i++) {
        if (!deleted[i]) printf("%c", s1[i]);
    }
    printf("\n");
}
