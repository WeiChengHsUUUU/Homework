#include <stdio.h>

int arr[1001][1001];

int main(void)
{
    int n;
    int ans;

    scanf("%d", &n);
    for(int x = 0;x < n;x++){
        for(int y = 0;y < n;y++){
            scanf("%d", &arr[x][y]);
        }
    }

    for(int x = 0;x < n;x++){
        ans = -1;
        for(int y = 0;y < n;y++){
            if(arr[x][y] > ans){
                ans = arr[x][y];
            }
        }
        if(x+1 == n){
            printf("%d", ans);
        }else{
            printf("%d ", ans);
        }
    }
    printf("\n");

    for(int y = 0;y < n;y++){
        ans = 50001;
        for(int x = 0;x < n;x++){
            if(arr[x][y] < ans){
                ans = arr[x][y];
            }
        }
        if(y+1 == n){
            printf("%d", ans);
        }else{
            printf("%d ", ans);
        }
    }
    printf("\n");

    return 0;
}
