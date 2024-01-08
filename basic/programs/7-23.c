#include <stdio.h>

void transform(int amount, int pos, int has_non_zero, int next_number_is_zero);

const char t[] = "abcdefghij";
const char unit[] = " SBQWSBQY";

int main() {
    int amount;
    scanf("%d", &amount);

    transform(amount, 0, 0, 0);

}

void transform(int amount, int pos, int has_non_zero, int next_number_is_zero) {
    if (amount == 0) {
        if (pos == 0) printf("%c", t[0]);
        return;
    };
    int remainder;
    remainder = amount % 10;
    amount = amount / 10;

    // 余数不为零 把has_non_zero设置为1
    transform(amount, pos+1, remainder!=0 ? 1 : has_non_zero, remainder == 0);

    // 不为零
    if (remainder != 0) {
        printf("%c", t[remainder]);
        if (pos != 0) printf("%c", unit[pos]);
    } else {
        if (pos == 4) {
            printf("%c", unit[4]);
        } else if (has_non_zero && !next_number_is_zero) {
            printf("%c", t[0]);
        }
    }
}