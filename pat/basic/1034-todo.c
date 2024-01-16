#include <stdio.h>

typedef struct rational {
    long long a, b;
} rational;

void print_num(rational x);
long long gcd(long long a, long long b);
rational simply(rational x);
rational sum(rational x, rational y);
rational difference(rational x, rational y);
rational product(rational x, rational y);
rational quotient(rational x, rational y);

int main(void) {
    rational x={0}, y={0};
    scanf("%lld/%lld %lld/%lld", &x.a, &x.b, &y.a, &y.b);

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
    long long g;
    if (x.a == 0 || x.b == 0) return x;
    g = gcd(x.a, x.b);
    x.a = x.a / g;
    x.b = x.b / g;

    // 如果y.a为负，需要反转分子分母的符号
    if (x.b < 0) {
        x.a *= -1;
        x.b *= -1;
    }

    return x;
}

rational sum(rational x, rational y) {
    rational res = {0};
    //long long g = gcd (x.b, y.b);
    res.a = y.b * x.a + x.b * y.a;
    res.b = x.b * y.b;

    return simply(res);
}

rational difference(rational x, rational y) {
    rational res = {0};
    long long g = gcd (x.b, y.b);
    res.a = y.b / g * x.a - x.b / g * y.a;
    res.b = x.b / g * y.b;

    return simply(res);
}

rational product(rational x, rational y) {
    if (x.a == 0) return x;
    if (y.a == 0) return y;

    rational res = {0};
    // long long g1 = gcd(x.a, y.b);
    // long long g2 = gcd(y.a, x.b);
    // res.a = (x.a/g1) * (y.a/g2);
    // res.b = (x.b/g1) * (y.b/g2);
    res.a = x.a * y.a;
    res.b = x.b * y.b;

    return simply(res);
}

rational quotient(rational x, rational y) {
    if (y.a == 0) {
        x.b = 0;
        return x;
    }
    if (x.a == 0) return x;


    rational res = {0};
    res.a = x.a * y.b;
    res.b = x.b * y.a;

    return simply(res);
}

long long gcd(long long a, long long b) {
    long long temp;
    while (b) {
        temp = b;
        b = a % b;
        a = temp;
    }

    if (a<0) return -1 * a;

    return a;
}

void print_num(rational x) {
    if (x.b == 0) {
        printf("Inf");
        return;
    }
    long long sign = x.a < 0 ? -1 : 1;
    x.a = sign * x.a;
    if (sign == -1) printf("(-");

    // 分母为1 或者 分子为0
    if (x.b == 1 || x.a == 0) {
        printf("%lld", x.a);
    } else {
        long long integral = x.a/x.b, remainder = 0;
        if (integral) printf("%lld ", integral);
        remainder = x.a % x.b;
        printf("%lld/%lld", remainder, x.b);
    }

    if (sign == -1) printf(")");
}