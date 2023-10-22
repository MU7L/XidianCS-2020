#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    int n, m;
    cin >> n >> m;
    int matrix[100][100] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }
    bool exist = false;
    bool flag = true;
    for(int i = 0; i < n; i++){
        flag = true;
        int minId = 0;
        for(int j = 0; j < m; j++){
            if(matrix[i][j] < matrix[i][minId]){
                minId = j;
            }
        } //第i行最小值为matrix[i][minId]
        for(int k = 0; k < n; k++){
            if(matrix[k][minId] > matrix[i][minId]){
                flag = false;
                break; //matrix[i][minId]不是第j列最大值
            }
        }
        if(flag){
            exist = true;
            cout << i + 1 << ' ' << minId + 1 << ' ' << matrix[i][minId] << endl;
        }
    }
    if(!exist){
        cout << "NO" << endl;
    }
    return 0;
}

/*

4 4
2 7 9 10
1 0 7 12
8 23 13 15
4 6 12 18

3 1 8

*/