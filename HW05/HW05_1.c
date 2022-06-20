 #include <stdio.h>

 int find_least(int a[5001], int n, int m, int k);
 int max(int x, int y);
 int min(int x, int y);
 int a[5001];

 int main(void)
 {
    int t;
    int n, m, k;

    scanf("%d", &t);

    while(t--){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0;i < n;i++){
            scanf("%d", &a[i]);
        }
        printf("%d\n", find_least(a, n, m, k));
    }

    return 0;
 }

 int find_least(int a[5001], int n, int m, int k)
 {
    int ans = -1;
    int least;
    int j, i;

    if(k >= m){
        k = m-1;
    }

    for(i = 0;i <= k;i++)/*a[i]~a[i+n-m]*/{
        least = 1000000000+1;
        for(j = 0;j <= m-k-1;j++)/*a[i+j]~a[i+j+n-m]*/{
            least = min(least, max(a[i+j], a[i+j+n-m]));
        }
            ans = max(ans, least);
    }

    return ans;
 }


int max(int x, int y)
 {
    if(x > y){
        return x;
    }else{
        return y;
    }
 }

int min(int x, int y)
 {
    if(x < y){
        return x;
    }else{
        return y;
    }
 }
