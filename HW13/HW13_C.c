#include <stdio.h>

long long int count_ans(int A, int B, int C, int D);
int min(int a, int b);

int main(void)
{
    int T, A, B, C, D;

    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &A, &B, &C, &D);
        printf("%lld\n", count_ans(A, B, C, D));
    }

    return 0;
}

long long int count_ans(int A, int B, int C, int D)
{
    int axy[100001] = {0};
    int prf[100001] = {0};
    long long int ans = 0;

    for(int x = A;x <= B;x++){
        ++axy[x+B];
        --axy[x+C+1];
    }

    for(int x = A+B;x <= B+C;x++){
        prf[x] = prf[x-1] + axy[x];
    }

    for(int x = C+1;x <= B+C;x++){
        ans += prf[x]*(min(x, D+1) - C);
    }

    return ans;
}

int min(int a, int b)
{
    if(a < b){
        return a;
    }else{
        return b;
    }
}
