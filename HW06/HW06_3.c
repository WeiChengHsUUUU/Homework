#include <stdio.h>
#include <string.h>

int MOD = 1e9+7;

char s[2*(int)1e6];
char temp[(int)1e6];

long long int howlong(int x);
void substr(int i,int  end);

int main(void)
{
    int t, x;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &x);
        scanf("%s", s);

        printf("%lld\n", howlong(x));
    }

    return 0;
}

long long int howlong(int x)
{
    long long int add;
    long long int l = strlen(s);
    int left;
    long long int s_len = l;
    long long int t_len;

    for(int i = 1;i <= x;i++){
        left = s[i-1] - '0';
        add = ((l-i)%MOD * (left-1))%MOD;
        l = (l+add)%MOD;

        if(s_len <= x && left >1){
            substr(i, s_len);
            t_len = strlen(temp);
            for(int j = 1;j <= left - 1;j++){
                if(s_len > x)
                    break;
                strcat(s, temp);
                s_len += t_len;
            }
        }
    }
    if(l < 0)
        l += MOD;

    return l;
}

void substr(int i,int  end)
{
    int e = 0;
    for(int j = i;j <= end;j++){
        temp[e] = s[j];
        e++;
    }
    temp[e] = '\0';
}
