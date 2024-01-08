#include <stdio.h>

double f(double x);
double find_solution(double start, double end);

double a3, a2, a1, a0;

int main() {
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
    double start, end;
    scanf ("%lf %lf", &start, &end);

    printf("%.2lf\n", find_solution(start,end));
}

double find_solution(double start, double end) {
    if(end-start < 0.005) return (end+start)/2.0;

    double mid = f((start+end)/2.0);
    if(mid==0) return (end+start)/2.0;
    if(mid * f(start) > 0) return find_solution((start+end)/2.0, end);
    if(mid * f(end) > 0) return find_solution(start, (start+end)/2.0);
}

double f(double x) {
    return a3 * x * x * x + a2 * x * x + a1 * x  + a0;
}
