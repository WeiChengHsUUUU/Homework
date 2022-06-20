#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char str[7*(int)1e6];
char temp[(int)1e6];

long long int howlong(int x);

int MOD = 1e9+7;

int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        scanf("%s", str);

        printf("%lld\n", howlong(x));

    }

    return 0;
}

long long int howlong(int x)
{
    long long int length_mod,add_mod;
    long long int len_str = strlen(str);
    length_mod=len_str;

    long long int t_len;
    for (int i = 1; i<=x; i++) {
        int left = str[i-1]-'0';
        add_mod = ((length_mod-i)%MOD * (left-1))%MOD;
        length_mod = (length_mod+add_mod)%MOD;
        if (len_str <= x && left > 1) {
            int e = 0;
            for (int z = i; z < len_str; z++) {
                temp[e++] = str[z];
            }
            temp[e++] = '\0';
            t_len=len_str-i;
            for (int j = 0; j < left-1; j++) {
                if (len_str > x) {
                    break;
                }
                strcat(str, temp);
                len_str = len_str+t_len;
            }
        }
    }
    if (length_mod < 0) {
        length_mod = length_mod+MOD;
    }
    return length_mod;
}
