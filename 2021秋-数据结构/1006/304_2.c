#include<stdio.h>

typedef struct E{
	int u; //点
	int v; //点
	int w; //权重
}E;

E Edge[101];

int main(){
    int i, j; //循环变量
	int n, m; //输入
    int vest[50];
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++){
		vest[i] = i;
    }
	for(i = 1; i <= m; i++){
		scanf("%d %d %d", &Edge[i].u, &Edge[i].v, &Edge[i].w);
    }
    E t; //交换变量
	for(i = 1; i <= m; i++){//将边按权值大小顺序排列
		for(j = i + 1; j < m; j++){
			if(Edge[i].w > Edge[j].w){
				t = Edge[j];
				Edge[j] = Edge[i];
				Edge[i] = t;
			}
        }
    }
	int count = 1;
    j = 1;
    int sv, su;
	while(count < n){
		if(vest[Edge[j].u] != vest[Edge[j].v]){
            count++;

			//按大小输出
			if(Edge[j].u > Edge[j].v){
				printf("%d %d %d\n", Edge[j].v, Edge[j].u, Edge[j].w);
            }
			else{
			    printf("%d %d %d\n", Edge[j].u, Edge[j].v, Edge[j].w);
            }

			su = vest[Edge[j].u];
            sv = vest[Edge[j].v];
			for(i = 1; i <= n; i++){
				if(vest[i] == sv)
					vest[i] = su;//两个集合统一编号
			}
		}
		j++;//扫描下一个边
	}
	return 0;
}