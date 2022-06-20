#include <stdio.h>

int main(void)
{
    int A, B, C;
    int a, b, c;

    scanf("%d %d %d", &A, &B, &C);
    a = (A+B+C)/2-B;
    b = (A+B+C)/2-C;
    c = (A+B+C)/2-A;

    printf("%d %d %d\n", a, b, c);

    return 0;
}
