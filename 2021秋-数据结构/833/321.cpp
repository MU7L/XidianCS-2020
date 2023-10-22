#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mtx[1001][1001] = {0};

int main(int argc, char* argv[]){
    int cities = 0;
    int rails = 0;
    cin >> cities >> rails;
    int a, b;
    for(int i = 1; i <= rails; i++){
        cin >> a >> b;
        mtx[a][b] = 1;
        mtx[b][a] = 1;
    }

    int city = 1;
    int sets = 0;
    bool check[1001] = {false};
    bool loop = true;
    queue<int> searching;

    while(true){
        loop = false;
        for(int i = 1; i <= cities; i++){
            if(!check[i]){
                city = i;
                loop = true;
                break;
            }
        }
        if(!loop){
            break;
        }
        searching.push(city);
        while(!searching.empty()){
            city = searching.front();
            check[city] = true;
            searching.pop();
            for(int i = city + 1; i <= cities; i++){
                if(mtx[city][i] == 1 && check[i] == false){
                    check[i] = true;
                    searching.push(i);
                }
            }
        }
        sets++;
    }

    cout << sets - 1 << endl;

    return 0;
}

/*

9 8
1 2
1 3
2 4
3 4
5 7
5 6
6 7
8 9

2

*/