#include <stdio.h>

int main() {
    int wage;

    double salary;
    
    int seniority, working_hours;
    scanf("%d %d", &seniority, &working_hours);

    wage = seniority < 5 ? 30 : 50;

    if (working_hours <= 40) {
        salary = wage * working_hours;
    } else {
        salary = wage * 40 + wage * 1.5 * (working_hours-40);
    }

    printf("%.2f\n", salary);
}