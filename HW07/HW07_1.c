#include <stdio.h>
#define N 1000

int gcd(int x, int y);
int a[N+1];

int main(void)
{
    int n;
    int temp;
    int ans = 0;

    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1;i <= n;i++){
        for(int j = i+1;j <= n;j++){
            temp = gcd(a[i], a[j]);
            //printf("%d\n", temp);
            if(ans < temp){
                ans = temp;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}

int gcd(int x, int y)
{
    if(x == 0){
        return y;
    }else{
        return gcd(y%x, x);
    }
}
