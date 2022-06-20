#include <stdio.h>

void prt(int *z);

int main(void)
{
    float x;
    int *z;

    while(scanf("%f", &x) != EOF){
        int y = *((int*)&x);
        z = &y;
        prt(z);
    }

    return 0;
}

void prt(int *z)
{
    for(int i = 31;i >= 0;i--){
        if((*z & (1<<i)) != 0){
            printf("1");
        }else{
            printf("0");
        }
    }
    printf("\n");
}
