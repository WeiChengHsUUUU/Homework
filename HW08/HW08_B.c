#include <stdio.h>

long long int fpw(long long int x, long long int y, long long int m);

int main(void)
{
    long long int x;
    long long int y;
    long long int m;

    scanf("%lld%lld%lld", &x, &y, &m);
    printf("%lld\n", fpw(x, y, m));

    return 0;
}

long long int fpw(long long int x, long long int y, long long int m)
{
    if(y == 0)
        return 1 % m;
    long long int tmp;
    if(y%2 == 0){
        tmp = fpw(x, y/2, m);
        return tmp * tmp % m;
    }else{
        tmp = fpw(x, y/2, m);
        return ((tmp * tmp % m) * x) % m;
    }
}
