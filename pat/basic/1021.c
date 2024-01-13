#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1002

int main() {
    char number[MAX_SIZE];
    int counter[10];
    scanf("%s", &number);

    int i;
    int length = strlen(number);
    for (i=0;i<10;i++) counter[i] = 0;

    for (i=0;i<length;i++) {
        counter[number[i]-'0']++;
    }
    
    for (i=0;i<10;i++) {
        if(counter[i] > 0) printf("%d:%d\n", i, counter[i]);
    }
}