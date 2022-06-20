#include <stdio.h>
#define MOD 1000000007

typedef struct mux{
    long long s00;
    long long s01;
    long long s10;
    long long s11;
}mux;

mux bas = {1, 0, 0, 1};

mux fpw(mux a, long long int i);

mux muxmult(mux a, mux b);

int main(void)
{
    long long int i;
    mux first= {1, 1, 1, 0};
    mux m;

    while(scanf("%lld", &i) != EOF){
        if(i == 1){
            printf("1\n");
        }else{
            m = fpw(first, i-2);
            printf("%lld\n", (m.s00%MOD + m.s01%MOD)%MOD);
        }

    }

    return 0;
}

mux muxmult(mux a, mux b)
{
    mux ans;

    ans.s00 = ((a.s00*b.s00)%MOD + (a.s01*b.s10)%MOD)%MOD;
    ans.s01 = ((a.s00*b.s01)%MOD + (a.s01*b.s11)%MOD)%MOD;
    ans.s10 = ((a.s10*b.s00)%MOD + (a.s11*b.s10)%MOD)%MOD;
    ans.s11 = ((a.s10*b.s01)%MOD + (a.s11*b.s11)%MOD)%MOD;

    return ans;
}

mux fpw(mux a, long long int i)
{
    if(i == 0)
        return bas;
    mux temp;
    if(i % 2 == 0){
        temp = fpw(a, i/2);
        return muxmult(temp, temp);
    }else{
        temp = fpw(a, i/2);
        return muxmult(a, muxmult(temp, temp));
    }
}
