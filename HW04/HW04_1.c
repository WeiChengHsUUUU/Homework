#include <stdio.h>

int x[(int)1e6+1];
int count_1(int );

int main(void)
{
    for(int i = 1;i <= (int)1e6;i++){
        x[i] = x[i-1] + count_1(i);
    }

    int t;
    int a, b;

    scanf("%d", &t);

    while(t--){
        scanf("%d%d", &a, &b);
        printf("%d\n", x[b] - x[a-1]);
    }


    return 0;
}

int count_1(int d)
{
    int ans = 0;
    while(d){
        if(d%10 == 1){
            ans++;
        }
        d /= 10;
    }
    return ans;
}
