 #include<stdio.h>
#include<string.h>
#include<stdlib.h>

char Knuckles[1001][1001];
int n;
int i;
int compare(const void *a, const void *b)
{
    char cmpab[2001],cmpba[2001]={0};
    //ab v.s. ba//
    strcpy(cmpab,a);
    strcat(cmpab,b);
    strcpy(cmpba,b);
    strcat(cmpba,a);
    int x=strcmp(cmpab,cmpba);//ab<ba return 1 ab>ba return -1 else return 0//
    return -x;//盢耕计耚玡//
}
int main(void)
{
    while((scanf("%d",&n))!=EOF)
    {
        //盢块计锣Θstring皚//
        for(i=0;i<n;i++)
        {
            scanf("%s",Knuckles[i]);//块string//
        }
        //void qsort( void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *) )//
        //size:皚い–じ byte 虫//
        //comp:ゑ耕ノㄧ计肚璽计材把计ゑ材把计肚タ计材把计ゑ材把计肚0ㄢ把计单//
        qsort(Knuckles,n,1001*sizeof(char),compare);
        for(i=0;i<n;i++)
        {
            printf("%s",Knuckles[i]);
        }
        printf("\n");
    }
}
