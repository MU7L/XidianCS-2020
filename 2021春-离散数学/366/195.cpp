#include <iostream>

using namespace std;

int a[10][10]={0};
int n=0;

//判断自反性
bool isZiFj(){
    bool flag=true;
    for(int i=0;i<n;i++){
        if(a[i][i]==0){
            flag=false;
        }
    }
    return flag;
}

//判断对称性
bool isDvIf(){
    bool flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=a[j][i]){
                flag=false;
            }
        }
    }
    return flag;
}

//判断传递性
bool isIrDi(){
    bool flag=true;
    int multi[10][10]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                multi[i][j]+=a[i][k]*a[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(multi[i][j]==0 && a[i][j]!=0){
                flag=false;
            }
        }
    }
    return flag;
}

//判断等价关系
bool isDgJx(){
    bool flag1=isZiFj();
    bool flag2=isDvIf();
    bool flag3=isIrDi();
    return flag1 && flag2 && flag3;
}

int main(void){
    //输入
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    //判断输出
    if(isDgJx()){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
}