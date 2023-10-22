#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,m,R[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&R[i][j]);
        }
    }
    printf("r(R):\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                m=1;
            }
            else
            {
                m=R[i][j];
            }
            printf("%d ",m);
        }
        printf("\n");
    }
    printf("s(R):\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(R[i][j]+R[j][i]>=1)
            {
                R[i][j]=1;
            }
            printf("%d ",R[i][j]);
        }
        printf("\n");
    }
    return 0;
}