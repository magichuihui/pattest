#include <stdio.h>
#include <string.h>

#define MAX_SIZE 256

int main(void) {
    int i, j, broken[MAX_SIZE];
    for(i=0;i<MAX_SIZE;i++) broken[i] = 0;

    char s1[81], s2[81];
    scanf("%s", &s1);
    scanf("%s", &s2);

    char index;

    int length = strlen(s1);
    for (i=0,j=0;i<length;i++) {
        // 按键没坏
        if (s1[i] == s2[j]) {
            j++;
        } else {
            index = s1[i];
            if (s1[i] >= 'a' && s1[i] <= 'z') index += 'A' - 'a';
            if (broken[index] == 0) printf("%c", index);
            broken[index]++;
        }
    }

}