#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void print_number(int n, int tail);

char *str_numbers[11] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    char number[MAX_SIZE + 1];
    scanf("%s", &number);
    
    int i, sum = 0;
    int length = strlen(number);
    for (i=0; i<length; i++) {
        sum += number[i] - 0x30;
    }

    print_number(sum, 1);
}

void print_number(int n, int tail) {
    if (n==0) {
        printf("ling\n");
        return;
    }

    int remainder = n % 10;
    n = n / 10;

    if (n != 0) print_number(n, 0);

    printf("%s", str_numbers[remainder]);
    if (tail) {
        printf("\n");
    } else {
        printf(" ");
    }
}