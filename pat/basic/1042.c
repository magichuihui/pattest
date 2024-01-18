#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1002

int main(void) {
    char str[MAX_SIZE];
    fgets(str, MAX_SIZE, stdin);

    int length = strlen(str)-1;

    str[length] = 0;
    int i;

    int counter[26];
    for (i=0;i<26;i++) counter[i]=0;
    for (i=0;i<length;i++) {
        if (str[i]<='z' && str[i]>='a') counter[str[i]-'a']++;
        if (str[i]<='Z' && str[i]>='A') counter[str[i]-'A']++;
    }

    int max = 0;
    for (i=1;i<26;i++) if (counter[i]>counter[max]) max = i;

    printf("%c %d\n", 'a'+max, counter[max]);
}