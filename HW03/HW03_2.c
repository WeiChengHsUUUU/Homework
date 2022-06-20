 #include <stdio.h>

int main(void)
{
    int appear[(int)2e5+1] = {0};
    int a[(int)2e5+1];
    int b[(int)2e5+1];
    int n;
    int start = 0;

    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0;i < n;i++){
        scanf("%d", &b[i]);
    }

    for(int find = 0;find < n;find++){
        int count = 0;

        if(appear[b[find]] == 0){
            for(;start < n;start++){
                count++;
                appear[a[start]] = 1;
                if(a[start] == b[find]){
                    start++;
                    break;
                }
            }
        }
        printf("%d", count);
        if(find+1 < n){
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
