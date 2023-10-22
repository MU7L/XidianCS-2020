#include<stdio.h>

int f[31];
//用f[x]=y表示x点和y点相连

int find(int x){
	return f[x] == x ? x : f[x] = find(f[x]);
	// 设 f={0,1,2,9,4,5,6,7,8,8}
	// 传入x = 3,
	// 因为f[3] != 3，返回f[3] = find(f[3]) 即 f[3] = find(9)
	// 这一层返回f[3]的值
	// find(9)，返回f[9] = find(f[9]) = find(8)
	// 这一层返回f[9]的值
	// find(8) = 8
	// 回上一层，f[9] = 8
	// 回上一层，f[3] = f[9] = 8
	// 最后返回8
	// f={0,1,2,8,4,5,6,7,8,8}

	// 联通的点在f[]中的值相等
}

//链接x和y
void unio(int x,int y){ //unio(E e)
	int fx = find(x), fy = find(y);
	f[fx] = fy; //链接函数
}

typedef struct E{
	int x1, x2, w, flag; //flag标志读入树中
}e;

e es[101];

int main(){
	int n, m; //点 边
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		f[i] = i;
	}
	//输入边
	for(int i = 0; i < m; i++){
		int k1, k2;
		scanf("%d%d%d", &k1, &k2, &es[i].w);
		if(k1 > k2){
			int temp = k1;
			k1 = k2;
			k2 = temp;
		}
		es[i].x1 = k1;
		es[i].x2 = k2;
	}
	//es边集排序 升序
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m - i - 1; j++){
			if(es[j].w > es[j + 1].w){
				e temp = es[j];
				es[j] = es[j + 1];
				es[j + 1] = temp;
			}
		}
	}
	es[0].flag = 1;
	unio(f[es[0].x1], f[es[0].x2]); //按es[0]边连接
	for(int i = 1; i < m; i++){
		if(find(es[i].x1) == find(es[i].x2)){ //es[i]的两端点在加上该边前已连接 该边不读入树
			continue;
		}
		else{
			//将es[i]读入树并连接两端点
			es[i].flag = 1;
			unio(es[i].x1, es[i].x2);
		}
	}
	for(int i=0;i<m;i++){
		if(es[i].flag){ //flag=true 的边为生成树
			printf("%d %d %d\n", es[i].x1, es[i].x2, es[i].w);
		}
	}
	return 0;
}
