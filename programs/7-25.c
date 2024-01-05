#include <stdio.h>

void print_number(int n, int last);

const char *numbers[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
    int n;
    scanf("%d", &n);

    print_number(n, 1);    
}

void print_number(int n, int last) {
    if (n<0) {
        printf("fu ");
        n *= -1;
    }

    int remainder;
    remainder = n % 10;
    
    if(n / 10 != 0) {
        print_number(n/10, 0);
    }

    printf("%s", numbers[remainder]);
    if (!last) printf(" ");
}