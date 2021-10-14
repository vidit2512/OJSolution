#include<stdio.h>
int main()
{
    int t,a,b;
    scanf("%d",&t);
    
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a>0&&b>0)
        {
        printf("Solution");
        }
        else if(a==0&&b>0)
        {
            printf("Liquid");
        }
        else if(a>0&&b==0)
        {
            printf("Solid");
        }
        return 0;
        
    }
}