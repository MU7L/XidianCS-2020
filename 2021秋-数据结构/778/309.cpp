#include <iostream>
#include <cstring>

using namespace std;

class Matrix{
public:
    int B[10][10];
    int m, n;
    int V[10];
    int vLen;

    Matrix(int m, int n){
        this ->m = m;
        this ->n = n;
        memset(B, 0, sizeof(B));
        memset(V, 0, sizeof(V));
        vLen = 0;
    }

    void setValue(){
        setB();
        setV();
    }

    void setB(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> B[i][j];
                if(B[i][j] == 1){
                    vLen++;
                }
            }
        }
    }

    void setV(){
        for(int k = 0; k < vLen; k++){
            cin >> V[k];
        }
    }

    void showB(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << B[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void showV(){
        for(int k = 0; k < vLen; k++){
            cout << V[k] << ' ';
        }
        cout << endl;
    }

    Matrix add(const Matrix *mtx){
        int a = 0;
        int b = 0;
        Matrix res(m, n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(B[i][j]){
                    res.B[i][j] = 1;
                    res.V[res.vLen] += V[a++];
                }
                if(mtx ->B[i][j]){
                    res.B[i][j] = 1;
                    res.V[res.vLen] += mtx ->V[b++];;
                }
                if(res.V[res.vLen]){
                    res.vLen++;
                }
                else{
                    res.B[i][j] = 0;
                }
            }
        }
        return res;
    }

    void show(){
        showB();
        showV();
    }
};

int main(int argc, char* argv[]){
    int m, n;
    cin >> m >> n;
    Matrix A(m, n);
    A.setValue();
    //A.show();
    Matrix B(m, n);
    B.setValue();
    Matrix C = A.add(&B);
    C.show();

    return 0;
}

/*

3 4
1 0 0 1
0 1 0 0
1 0 0 0
15 22 -6 9
0 1 1 0
0 1 1 0
1 0 0 1
3 2 6 2 -5 8

1 1 1 1
0 0 1 0
1 0 0 1
15 3 2 22 4 8

*/