#include <stdio.h>

void bike(long long int k, int n);

long long int arr[100001] = {0};

int main(void)
{
    int n;
    long long int k;

    scanf("%d%lld", &n, &k);
    for(int x = 1;x <= n;x++){
        scanf("%lld", &arr[x]);
    }

    bike(k, n);

    return 0;
}

void bike(long long int k, int n)
{
    long long int pos = 0;
    int cp = 0;
    int sign = 0;

    for(long long int i = 1;i <= n;i++){
        if(pos + k < arr[i] && arr[i-1] == pos){
            printf("The Legend Falls.\n");
            sign = 1;
            break;
        }else if(pos + k < arr[i]){
            //printf("__%d\n", i-1);
            cp++;
            pos = arr[i-1];
            i--;
        }else{
            continue;
        }
    }
    if(sign == 0)
        printf("%d\n", cp);
}
