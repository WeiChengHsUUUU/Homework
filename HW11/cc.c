#include <stdio.h>
#include <stdlib.h>

int al_arr[100001];
long long int ln_arr[100001];
int num[100001];

int compare(const void *a, const void *b)
{
	const int *va = (const int *) a;
    const int *vb = (const int *) b;

    if(al_arr[*va] < al_arr[*vb])
        return -1;
    if(al_arr[*va] > al_arr[*vb])
        return 1;
    if(ln_arr[*va] < ln_arr[*vb])
        return -1;
    if(ln_arr[*va] > ln_arr[*vb])
        return 1;
    return 0;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    for(int x = 0;x < n;x++){
        scanf("%d%lld", &al_arr[x], &ln_arr[x]);
        num[x] = x;
    }

    qsort(num, n, sizeof(int), compare);

    for(int x = 0;x < n-1;x++){
        printf("%d ", num[x]+1);
    }
    printf("%d\n", num[n-1]+1);

    return 0;
}
