#include<stdio.h>
int main(){
    int n=0;
    scanf("%d",&n);
    int a[n][n],b[n][n],p[n][n],c[n][n];
    int i=0,j=0,k=0,z=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            b[i][j]=0;
            p[i][j]=a[i][j];
            if(i==j)
                p[i][j]=1;
            c[i][j]=a[i][j];
        }
    }
    for(z=0;z<n-1;z++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++)
                    b[i][j]+=c[i][k]*a[k][j];
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(p[i][j]==1 || b[i][j]>0)
                    p[i][j]=1;
                c[i][j]=b[i][j];
            }
        }
    }
 /*   for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }*/
    int glt=1,dxlt=1,rlt=1;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(p[i][j]==0)
                glt=0;
            if((p[i][j]+p[j][i])==0)
                dxlt=0;
        }
    }
    if(glt==1)
        printf("qlt");
    if(glt==0 && dxlt==1)
        printf("dxlt");
    if(glt==0 && dxlt==0){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i][j]==1 || a[j][i]==1)
                    a[i][j]=1;
                p[i][j]=a[i][j];
                if(i==j)
                    p[i][j]=1;
                b[i][j]=0;
                c[i][j]=a[i][j];
            }
        }

        for(z=0;z<n-1;z++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    for(k=0;k<n;k++)
                         b[i][j]+=c[i][k]*a[k][j];
                }
            }

            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(p[i][j]==1 || b[i][j]>0)
                        p[i][j]=1;
                    c[i][j]=b[i][j];
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(p[i][j]==0)
                    rlt=0;
            }
        }
        if(rlt==1)
            printf("rlt");
        else
            printf("blt");
    }
    return 0;
}
