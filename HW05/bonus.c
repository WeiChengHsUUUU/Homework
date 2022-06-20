#include <stdio.h>

char a[1000+1];
char a2[1000+1];
int sum[1000+1] = {0};

void prifixsum(int i, int j);

int main(void)
{
    char c;
    int t;
    int l, r;
    int i, j;

    i = 0;
    while((c = getchar()) != '\n'){
        i++;
        a[i] = c;
    }

    j = 0;
    while((c = getchar()) != '\n'){
        j++;
        a2[j] = c;
    }

    prifixsum(i, j);

    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &l, &r);

        printf("%d\n", sum[r-j+1] - sum[l-1]);
    }

    return 0;
}

void prifixsum(int i, int j)
{
    int signn;

    for(int x = 1;x <= i;x++){
        signn = 0;
        for(int y = 1;y <= j;y++){
            if(a2[y] != a[x+y-1]){
                signn = 1;
                break;
            }
        }
        if(signn == 0){
            sum[x] = 1;
        }
    }
    for(int x = 1;x <= i;x++){
        sum[x] = sum[x] + sum[x-1];
    }
}
