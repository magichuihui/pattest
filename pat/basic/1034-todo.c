#include <stdio.h>

typedef struct rational {
    int a, b;
} rational;

void print_num(rational x);
int gcd(int a, int b);
rational simply(rational x);
rational sum(rational x, rational y);
rational difference(rational x, rational y);
rational product(rational x, rational y);
rational quotient(rational x, rational y);

int main(void) {
    rational x={0}, y={0};
    scanf("%d/%d %d/%d", &x.a, &x.b, &y.a, &y.b);

    x = simply(x);
    y = simply(y);

    // +
    print_num(x);
    printf(" + ");
    print_num(y);
    printf(" = ");
    print_num(sum(x,y));
    printf("\n");
    // -
    print_num(x);
    printf(" - ");
    print_num(y);
    printf(" = ");
    print_num(difference(x,y));
    printf("\n");
    // *
    print_num(x);
    printf(" * ");
    print_num(y);
    printf(" = ");
    print_num(product(x,y));
    printf("\n");
    // /
    print_num(x);
    printf(" / ");
    print_num(y);
    printf(" = ");
    print_num(quotient(x,y));
    printf("\n");
}

rational simply(rational x) {
    int sign=1, g;
    if (x.a == 0) return x;
    if (x.a < 0) sign=-1;
    g = gcd(sign * x.a, x.b);
    x.a = x.a / g;
    x.b = x.b / g;

    return x;
}

rational sum(rational x, rational y) {
    rational res = {0};
    res.a = x.a * y.b + y.a * x.b;
    res.b = x.b * y.b;

    return simply(res);
}

rational difference(rational x, rational y) {
    rational res = {0};
    res.a = x.a * y.b - y.a * x.b;
    res.b = x.b * y.b;

    return simply(res);
}

rational product(rational x, rational y) {
    rational res = {0};
    int g1 = gcd(x.a, y.b);
    int g2 = gcd(y.a, x.b);
    res.a = x.a/g1 * y.a/g2;
    res.b = x.b/g1 * y.b/g2;

    return simply(res);
}

rational quotient(rational x, rational y) {
    int g1 = gcd(x.a, y.a);
    int g2 = gcd(y.b, x.b);

    rational res = {0};
    res.a = x.a/g1 * y.b/g2;
    res.b = x.b/g2 * y.a/g1;
    // 如果y.a为负，需要反转分子分母的符号
    if (res.b < 0) {
        res.a = -1 * res.a;
        res.b = -1 * res.b;
    }
    return simply(res);
}

int gcd(int a, int b) {
    int temp;
    while (b) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void print_num(rational x) {
    if (x.b == 0) {
        printf("Inf");
        return;
    }
    int sign = x.a < 0 ? -1 : 1;
    x.a = sign * x.a;
    if (sign == -1) printf("(-");

    // 分母为1 或者 分子为0
    if (x.b == 1 || x.a == 0) {
        printf("%d", x.a);
    } else {
        int integral = x.a/x.b, remainder = 0;
        if (integral) printf("%d ", integral);
        remainder = x.a % x.b;
        printf("%d/%d", remainder, x.b);
    }

    if (sign == -1) printf(")");
}