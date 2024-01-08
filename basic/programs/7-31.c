#include <stdio.h>
#include <string.h>

#define MAX_SIZE 101

int main() {
    char s[MAX_SIZE];
    int N, length;
    fgets(s, MAX_SIZE, stdin);
    // 删除换行
    s[strcspn(s, "\r\n")] = 0;

    scanf("\n%d", &N);

    length = strlen(s);

    N = N % length;
    char temp[MAX_SIZE]; 
    memmove(temp, s+N, length - N);
    memmove(temp+length-N, s, N);
    temp[length] = 0;

    printf("%s\n", temp);
}

