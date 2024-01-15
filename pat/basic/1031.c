#include <stdio.h>
#include <string.h>

int is_num(char str[], int len);
int checksum(char str[], int len);


int main(void) {
    int N;
    char id[19];
    scanf("%d", &N);

    int i, length, count=0;
    for (i=0;i<N;i++) {
        scanf("%s", &id);
        length = strlen(id);
        if (!is_num(id, length-1) || !checksum(id, length)) {
            printf("%s\n", id);
            count++;
        }
    }

    if (!count) printf("All passed\n");
}

int is_num(char str[], int len) {
    int i;
    for (i=0;i<len;i++) {
        if (str[i] > '9' || str[i] < '0') return 0;
    }

    return 1;
}

int checksum(char str[], int len) {
    int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    int i, Z=0;
    for (i=0;i<len-1;i++) {
        Z += weight[i] * (str[i] - '0');
    }
    Z = Z % 11;

    return str[len-1] == M[Z];
}