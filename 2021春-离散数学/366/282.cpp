#include<stdio.h>
#define N 100
int main()
{
 int n,i,j,a[N][N],b[N][N],c[N][N]={0};
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   if(i==j) b[i][j]=1;
   else b[i][j]=a[i][j];
   if(a[i][j]==1)
   {
    c[i][j]=1;
    c[j][i]=1;
   }
  }
 }
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("%d ",c[i][j]);
  }
  if(i<n-1) printf("\n");
 }
}
