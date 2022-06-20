#include <stdio.h>

int visited[10004] = {0};
int x[10004], y[10004];
int count = 0;
int r;

void dfs(int now, int n);
int connect(int a, int b);

int main(void)
{
    int n;
    int group = 0;
    int alone = 0;

    scanf("%d%d", &n, &r);
    for(int q = 0;q < n;q++){
        scanf("%d%d", &x[q], &y[q]);
    }
    for(int q = 0;q < n;q++){
        if(visited[q] != 1){
            count = 0;
            dfs(q, n);
            if(count >= 1){
                group++;
            }else{
                alone++;
            }
        }
    }

    printf("%d %d\n", alone, group);

    return 0;
}

void dfs(int now, int n)
{
    if(visited[now] == 1)
        return;
    visited[now] = 1;
    for(int i = 0;i < n;i++){
        if(i == now)
            continue;
        if(visited[i] == 1)
            continue;
        if(connect(now, i) == 1){
            count++;
            dfs(i, n);
        }
    }
}

int connect(int a, int b)
{
    if((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]) <= r*r)
        return 1;
    return 0;
}
