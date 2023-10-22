#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
    int v, e;
    cin >> v >> e;
    int mtx[31][31] = {0};
    int a, b;
    for(int i = 1; i <= e; i++){
        cin >> a >> b;
        mtx[a][b] = 1;
        mtx[b][a] = 1;
    }
    /*
    for(int i = 1; i <= v; i++){
        for(int j = 1; j <= v; j++){
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
    */
    bool visited[31] = {0};
    set<int> s; //集合表
    queue<int> q; //广搜队列
    vector<int> subGraph;
    bool loop = true;
    int node = 1; //起始点为1
    while(true){
        loop = false;
        //找起始点
        for(int i = 1; i <= v; i++){
            if(visited[i] == false){
                loop = true;
                node = i;
                break;
            }
        }
        if(!loop){ //所有结点均已访问
            break;
        }
        q.push(node);
        //从起始点开始广搜
        while(!q.empty()){
            node = q.front(); //从广搜队列取起始点
            q.pop();
            s.insert(node);
            visited[node] = true;
            for(int k = node + 1; k <= v; k++){
                if(mtx[node][k] == 1 && visited[k] == false){
                    s.insert(k);  //node与k归为一个集合
                    q.push(k);         //k入队q,预备下一循环访问k的邻接点
                    //visited[k] = true; //k已访问
                }
            }
        }
        subGraph.push_back(s.size());
        s.clear();
    }
    cout << subGraph.size() << endl;
    sort(subGraph.begin(), subGraph.end());
    for(auto i : subGraph){
        cout << i << ' ';
    }
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

3
2 3 4

9 9
1 2
1 3
2 4
3 4
5 7
5 6
6 7
8 9
4 5

2
2 7

1 0

1
1

2 0

2
1 1

3 3
1 2
1 3
2 3

1
3

5 3
1 2
1 3
4 5

2
2 3

*/