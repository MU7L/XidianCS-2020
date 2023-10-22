#include"stdio.h"

int main(void){
    int n;
    scanf("%d",&n);
    
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    int b[n];
    for(int i=0;i<n;i++){
        b[i]=a[i]%10;
        for(int j=1;j<4;j++){
            b[i]+=a[i]/10%10;
        }
    }

    for(int i=0;i<n;i++){
        printf("%d %d\n",a[i],b[i]);
    }

    for(int i=0;i<n;i++){
        int maxid=i;
        for(int j=i+1;j<n;j++){
            if(b[maxid]<b[j]){
                int temp_1=b[maxid];b[maxid]=b[j];b[j]=temp_1;
                int temp_2=a[maxid];a[maxid]=a[j];a[j]=temp_2;
            }
        }
    }

    for(int i=0;i<n-1;i++){
        if(b[i]==b[i+1]){
            if(a[i]>a[i+1]){
                int temp_3=a[i];a[i]=a[i+1];a[i+1]=temp_3;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d %d\n",a[i],b[i]);
    }
}