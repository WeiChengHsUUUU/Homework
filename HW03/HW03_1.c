#include <stdio.h>

int main(void)
{
    long long int n, p;
    long long int l, r;
    long long int a;
    long long int i;
    long long int row[1000000+1];
    long long int row_1[1000000+1];

    scanf("%lld %lld", &n, &p);

    for (i = 1;i <= n;i++){
        scanf("%lld(/`A`)/ ~I__I ", &a);
        row[i] = a;
    }

    row_1[0] = 0;
    row_1[1] = row[1];
    for(i = 2;i <= n;i++){
        row_1[i] = row_1[i-1] + row[i];
    }

    for(i = 1;i <= p;i++){
        scanf("%lld%lld", &l, &r);
        a = row_1[r] - row_1[l-1];
        printf("%lld\n", a);
    }


    return 0;
}
