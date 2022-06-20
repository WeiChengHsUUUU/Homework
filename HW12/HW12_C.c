#include <stdio.h>
#include <stdlib.h>

int d1[100001];
int d2[100001];
int goods[100001];

int compare(const void *a, const void *b)
{
    const int *va = (const int*) a;
    const int *vb = (const int*) b;

    return (d2[*vb] - d1[*vb]) - (d2[*va] - d1[*va]);
}

int main(void)
{
    long long int n, k, ans = 0;
    scanf("%lld%lld", &n, &k);

    for(int x = 0;x < n;x++){
        scanf("%d", &d1[x]);
    }
    for(int x = 0;x < n;x++){
        scanf("%d", &d2[x]);
        goods[x] = x;
    }

    qsort(goods, n, sizeof(int), compare);

    for(int x = 0;x < k;x++){
        ans+=d1[goods[x]];
    }
    while(d2[goods[k]] - d1[goods[k]] > 0 && k < n){
        ans+=d1[goods[k]];
        k++;
    }
    while(k < n){
        ans+=d2[goods[k]];
        k++;
    }

    printf("%lld\n", ans);

    return 0;
}
