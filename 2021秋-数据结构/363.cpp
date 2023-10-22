#include <stdio.h>
#include<iostream>
#include<vector>
#include<stdlib.h>


using namespace std;
vector<int>a;
class Treenode{
public:
	int val;
	Treenode*left;
	Treenode*right;
	Treenode(int x):val(x),left(NULL),right(NULL){}
};

int partition(vector<int>&a,int low,int high){
	int temp = a[low];         //暂存枢值 
	while(low != high)
	 {
	 	while(low < high && a[high] >= temp) high --;// 找小于轴值的记录
		a[low]=a[high];
		while (low < high && a[low] <= temp) low++ ;  //找大于轴值的记录
		a[high]=a[low];
	 }
 	a[low] = temp;
 	return low;
}

Treenode* Qssort(vector<int>&a,int low,int high){
	if(low>high) return NULL;
	int i=partition(a,low,high);
	Treenode*root=new Treenode(a[i]);
	root->left=Qssort(a,low,i-1);
	root->right=Qssort(a,i+1,high);
	return root;
}

void backordertrace(Treenode*root){
	if(root==NULL) return;
	backordertrace(root->left);
	backordertrace(root->right);
	cout<<root->val<<" ";
}

int main()
{
	int n = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		a.push_back(c);
	}
	Treenode*root;
	root=Qssort(a,0,n-1);   
	backordertrace(root); 
 	system("pause");
 	return 0;
} 