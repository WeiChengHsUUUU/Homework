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
    return -x;//�]���N���j�����\�e��//
}
int main(void)
{
    while((scanf("%d",&n))!=EOF)
    {
        //�N��J���Ʀr�নstring�A��J�}�C//
        for(i=0;i<n;i++)
        {
            scanf("%s",Knuckles[i]);//��Jstring//
        }
        //void qsort( void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *) )//
        //size:�b�}�C���C�Ӥ������j�p�A�H byte �����//
        //comp:����Ϊ���ơA�^�ǭt�ƥN��Ĥ@�ӰѼƤ�ĤG�ӰѼƤp�A�^�ǥ��ƥN��Ĥ@�ӰѼƤ�ĤG�ӰѼƤj�A�^��0�N���ӰѼƬ۵�//
        qsort(Knuckles,n,1001*sizeof(char),compare);
        for(i=0;i<n;i++)
        {
            printf("%s",Knuckles[i]);
        }
        printf("\n");
    }
}
