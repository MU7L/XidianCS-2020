/*2.2 写一个程序,构造关系的自反和对称闭包 */ 
#include<stdio.h>
#define N 4
int a[N][N];
 
void input( int n )
{
 int i,j;
 for( i=0;i<n;i++ ){
  for( j=0;j<n;j++ ){
   scanf("%d",&a[i][j]);
  }
 }
}
void output( int x[N][N] )
{
 int i,j;
 for( i=0;i<N;i++ ){
  for( j=0;j<N;j++ ){
   printf("%d ",x[i][j]);
  }
  printf("\n");
 }
}
void zifan( int n,int b[N][N])
{
 int i,j,I[n][n];
 //I为恒等关系 
 for( i=0;i<n;i++ ){
  I[i][i]=1;
 }
 //求自反闭包 
 for( i=0;i<n;i++ ){
  for( j=0;j<n;j++ ){
   if( a[i][j]==1||I[i][j]==1 ) b[i][j]=1;
  }
 }
}
void duicheng( int n,int b[N][N] )
{
 int i,j;
 //求对称闭包 
 for( i=0;i<n;i++ ){
  for( j=0;j<n;j++ ){
   if( a[i][j]==1 ){
    b[i][j]=1;
    b[j][i]=1;      //即并上逆矩阵 
   }
  }
 }
}
int main()
{
 int b[N][N]={0},c[N][N]={0};
 input( N );
 
// printf("自反闭包为：\n");
 //zifan( N,b );
 //output( b );
 
 
 duicheng( N,c );
 output( c );
  
 return 0;
}
