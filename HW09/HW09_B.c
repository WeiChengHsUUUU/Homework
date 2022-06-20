#include <stdio.h>

char arr[27];

int cheeck(int n);

int main(void)
{
    int n;

    scanf("%d", &n);
    if(cheeck(n)){
        printf("I'm the god of Knuckles!\n");
    }else{
         printf("Different makes perfect\n");
    }

    return 0;
}

int cheeck(int n)
{
    if(n < 2 || n > 26){
        return 1;
    }else{
        scanf("%s", &arr);

        int sign = 0;
        for(int x = 0;x < n;x++){
            for(int y = x+1;y < n;y++){
                if(arr[x] == arr[y])
                    sign = 1;
            }
        }
        if(sign == 1){
            return 1;
        }else{
            return 0;
        }
    }
}
