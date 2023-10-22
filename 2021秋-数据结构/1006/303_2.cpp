#include<stdio.h>
#include<queue>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int vis[201];
int G[201][201];
int v_sum;int a[201];
int n,m;
int dfs(int i){
	vis[i]=1;
	for(int j=1;j<=n;j++){
		if(vis[j]==0&&G[j][i]==1){
			v_sum++;
			dfs(j);
		}
	}
}
int main(){
scanf("%d%d",&n,&m);
	int v1,v2;
	while(m--){
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=1;G[v2][v1]=1;	
	}
	int s=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			dfs(i);
			s++;
		}
	}
	printf("%d\n",s);
		for(int i=1;i<=n;i++)vis[i]=0;
	int count=0;
		for(int i=1;i<=n;i++){
		if(vis[i]==0){
			v_sum=1;
			dfs(i);
		    a[count++]=v_sum;
		}
	}
	sort(a,a+count);
	for(int i=0;i<count;i++)printf("%d ",a[i]);
	
} 