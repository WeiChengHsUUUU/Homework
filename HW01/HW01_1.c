#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    if(a<=b){
        printf("%d %d\n", a, 2*a);
    }else{
        printf("error");
    }

    return 0;
}
