#include <stdio.h>
#include <stdlib.h>

long long int good[300002] = {0};
long long int prf[300002] = {0};

long long int compare(const void *a, const void *b)
{
    const long long int *va = (const long long int*)a;
    const long long int *vb = (const long long int*)b;

    return *va - *vb;
}

int main(void)
{
    int t, n, p, k;

    scanf("%d", &t);
    while(t--){
        int ans = 0;

        scanf("%d%d%d", &n, &p, &k);
        for(int x = 1;x <= n;x++){
            scanf("%lld", &good[x]);
        }
        qsort(good+1, n, sizeof(long long int), compare);
        for(int x = 1;x < k;x++){
            prf[x] = good[x] + prf[x-1];
        }
        for(int x = k;x <= n;x++){
            prf[x] = good[x] + prf[x-k];
        }

        for(int x = 1;x <= n;x++){
            if(prf[x] <= p)
                ans = x;
        }
        printf("%d\n", ans);
    }

    return 0;
}
