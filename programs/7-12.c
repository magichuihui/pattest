#include <stdio.h>

int main() {
    int op1, op2, res;
    char op;

    scanf("%d %c %d", &op1, &op, &op2);

    if (op == '+') {
        res = op1 + op2;
    } else if (op == '-') {
        res = op1 - op2;
    } else if (op == '*') {
        res = op1 * op2;
    } else if (op == '/') {
        res = op1 / op2;
    } else if (op == '%') {
        res = op1<0 ? -1 * op1 % op2 : op1 % op2;
    } else {
        printf("ERROR\n");
        return 0;
    }
    printf("%d\n", res);
    return 0;
}