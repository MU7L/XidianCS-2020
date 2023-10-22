#include"stdio.h"
int main(void){
	int n,a_1,a_2,para=1;
	scanf("%d",&n);
	scanf("%d",&a_1);
	for(int i=2;i<=n;i++){
		scanf("%d",&a_2);
		if(a_1!=a_2){
			para++;
		}
		a_1=a_2;
	}
	printf("%d",para);
}