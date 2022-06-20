#include <stdio.h>

void putqueen(int col, int N);
int check(int row, int col, int N);

int a[15];
int ans = 0;

int main(void)
{
    int N;

    scanf("%d", &N);
    putqueen(1, N);
    printf("%d\n", ans);

    return 0;
}

void putqueen(int col, int N)
{
    if(col > N){
        ans++;
    }else{
        for(int row = 1;row <= N;row++){
            if(check(row, col, N)){
                a[col] = row;
                putqueen(col+1, N);
            }
        }
    }
}

int check(int row, int col, int N)
{
    for(int precol = 1;precol < col;precol++){
        if(a[precol] == row || col-precol == row-a[precol] || col-precol == a[precol]-row)
            return 0;
    }
    return 1;
}
