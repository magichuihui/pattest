#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100002

int valid(char c);

int main(void) {
    char broken[44], input[MAX_SIZE];
    fgets(broken, 44, stdin);
    fgets(input, MAX_SIZE, stdin);

    broken[strlen(broken)-1] = 0;
    input[strlen(input)] = 0;
    
    int i, length=strlen(input);
    char temp;
    for (i=0;i<length;i++) {
        temp = input[i];
        if (!valid(temp)) continue;
        if (temp<='Z' && temp>='A' && strchr(broken, '+')!=NULL) continue;

        if (temp <= 'z' && temp >= 'a') temp += 'A' - 'a';
        if (strchr(broken, temp)) continue;
        printf("%c", input[i]);
    }
    printf("\n");
}

int valid(char c) {
    if (c<='Z' && c>='A') return 1;
    if (c<='z' && c>='a') return 1;
    if (c<='9' && c>='0') return 1;
    if (c=='_' || c==',' || c=='.' || c=='-' || c=='+') return 1;

    return 0;
}