#include <stdio.h>

#define MOD 1000000007

struct mat{
    long long int p00;
    long long int p01;
    long long int p02;
    long long int p10;
    long long int p11;
    long long int p12;
    long long int p20;
    long long int p21;
    long long int p22;
};
typedef struct mat mat;

mat z = {
    .p00 = 1,
    .p01 = 0,
    .p02 = 0,
    .p10 = 0,
    .p11 = 1,
    .p12 = 0,
    .p20 = 0,
    .p21 = 0,
    .p22 = 1
};

mat matmul(mat x, mat y);
mat fpw(mat x, long long int y);


int main(void)
{
    int t;
    long long int x;

    mat m = {
    .p00 = 1,
    .p01 = 2,
    .p02 = 1,
    .p10 = 1,
    .p11 = 0,
    .p12 = 0,
    .p20 = 0,
    .p21 = 1,
    .p22 = 0
    };
    mat n;

    scanf("%d", &t);
    while(t--){
        scanf("%lld", &x);
        if(x < 4){
            if(x == 1){
                printf("1\n");
            }else if(x == 2){
                printf("12\n");
            }else{
                printf("13\n");
            }
            continue;
        }
        n = fpw(m, x-3);
        printf("%lld\n", (n.p00*13 + n.p01*12 + n.p02*1)%MOD);
    }

    return 0;
}

mat matmul(mat x, mat y)
{
    mat ans;
    ans.p00 = ((x.p00*y.p00)%MOD + (x.p01*y.p10)%MOD + (x.p02*y.p20)%MOD)%MOD;
    ans.p01 = ((x.p00*y.p01)%MOD + (x.p01*y.p11)%MOD + (x.p02*y.p21)%MOD)%MOD;
    ans.p02 = ((x.p00*y.p02)%MOD + (x.p01*y.p12)%MOD + (x.p02*y.p22)%MOD)%MOD;
    ans.p10 = ((x.p10*y.p00)%MOD + (x.p11*y.p10)%MOD + (x.p12*y.p20)%MOD)%MOD;
    ans.p11 = ((x.p10*y.p01)%MOD + (x.p11*y.p11)%MOD + (x.p12*y.p21)%MOD)%MOD;
    ans.p12 = ((x.p10*y.p02)%MOD + (x.p11*y.p12)%MOD + (x.p12*y.p22)%MOD)%MOD;
    ans.p20 = ((x.p20*y.p00)%MOD + (x.p21*y.p10)%MOD + (x.p22*y.p20)%MOD)%MOD;
    ans.p21 = ((x.p20*y.p01)%MOD + (x.p21*y.p11)%MOD + (x.p22*y.p21)%MOD)%MOD;
    ans.p22 = ((x.p20*y.p02)%MOD + (x.p21*y.p12)%MOD + (x.p22*y.p22)%MOD)%MOD;

    return ans;
}

mat fpw(mat x, long long int y)
{
    if(y == 0)
        return z;
    mat tmp;
    if(y%2 == 0){
        tmp = fpw(x, y/2);
        return matmul(tmp, tmp);
    }else{
        tmp = fpw(x, y/2);
        return (matmul(matmul(tmp, tmp), x));
    }
}
