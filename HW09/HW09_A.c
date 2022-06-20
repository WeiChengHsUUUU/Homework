#include <stdio.h>

int bs(int str, long long int f, int n);

long long int arr[1000002];

int main(void)
{
    int n, k, q;
    scanf("%d%d%d", &n, &k, &q);

    for(int x = n-k+1;x <= n;x++){
        scanf("%lld", &arr[x]);
    }
    for(int x = 1;x < n-k+1;x++){
        scanf("%lld", &arr[x]);
    }

    long long int f;
    while(q--){
        scanf("%lld", &f);
        int sq1 = bs(1, f, n-k+1);
        int sq2 = bs(n-k+1, f, n+1);

        if(sq1 == -1 && sq2 == -1){
            printf("gan ni nya sai bau\n");
        }else if(sq1 == -1){
            printf("%d\n", sq2);
        }else if(sq2 == -1){
            printf("%d\n", sq1);
        }else{
            if(arr[sq1] > arr[sq2]){
                printf("%d\n", sq2);
            }else{
                printf("%d\n", sq1);
            }
        }
    }

    return 0;
}

int bs(int str, long long int f, int n)
{
    int l = str;
    int r = n;
    int ans = -1;
    while(l < r){
        int m = l - (l-r)/2;
        if(arr[m] >= f){
            r = m;
            ans = m;
        }else{
            l = m+1;
        }
    }
    return ans;
}
