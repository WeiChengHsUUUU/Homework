#include <stdio.h>

int main(void)
{
    int t;
    int temp;
    int r, g, b;

    scanf("%d", &t);

    for(int i = 0;i<t;i++){
        scanf("%d%d%d", &r, &g, &b);
        if(r > b){
            temp = r;
            r = b;
            b = temp;
        }
        if(g > b){
            temp = g;
            g = b;
            b = temp;
        }
        if(r > g){

            temp = g;
            g = r;
            r = temp;
        }
        //printf("%d %d %d\n", r, g, b);

        if(r+g >= b && g != b){
            printf("%d\n", (r+g-b)/2+b);
        }else if(r+g < b){
            printf("%d\n", r+g);
        }else if(r+g >= b && g == b){
            printf("%d\n", b+r/2);
        }
    }

    return 0;
}
