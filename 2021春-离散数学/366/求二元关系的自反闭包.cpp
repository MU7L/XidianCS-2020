/*2.2 дһ������,�����ϵ���Է��ͶԳƱհ� */ 
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
 //IΪ��ȹ�ϵ 
 for( i=0;i<n;i++ ){
  I[i][i]=1;
 }
 //���Է��հ� 
 for( i=0;i<n;i++ ){
  for( j=0;j<n;j++ ){
   if( a[i][j]==1||I[i][j]==1 ) b[i][j]=1;
  }
 }
}
void duicheng( int n,int b[N][N] )
{
 int i,j;
 //��ԳƱհ� 
 for( i=0;i<n;i++ ){
  for( j=0;j<n;j++ ){
   if( a[i][j]==1 ){
    b[i][j]=1;
    b[j][i]=1;      //����������� 
   }
  }
 }
}
int main()
{
 int b[N][N]={0},c[N][N]={0};
 input( N );
 
// printf("�Է��հ�Ϊ��\n");
 //zifan( N,b );
 //output( b );
 
 
 duicheng( N,c );
 output( c );
  
 return 0;
}
