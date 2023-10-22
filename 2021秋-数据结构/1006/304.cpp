#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Edge{
public:
    int v1;
    int v2;
    int weight;

    Edge(int v1, int v2, int weight){
        if(v1 > v2){
            int tmp = v1;
            v1 = v2;
            v2 = tmp;
        }
        this ->v1 = v1;
        this ->v2 = v2;
        this ->weight = weight;
    }
    void show(){
        cout << v1 << ' ' << v2 << ' ' << weight << endl;
    }
};

bool cmp(Edge a, Edge b){
    return a.weight < b.weight;
}

int main(int argc, char* argv[]){
    int v, e;
    cin >> v >> e;
    vector<Edge> G; //原图边集
    int v1, v2, w;
    while(e--){
        cin >> v1 >> v2 >> w;
        Edge edge(v1, v2 ,w);
        G.push_back(edge);
    }
    /*
    for(auto i : G){
        i.show();
    }
    */
    sort(G.begin(), G.end(), cmp); //按边权重升序
    set<int> visited; //已联通点的集合
    vector<Edge> T; //生成树的边集
    for(auto E : G){
        if(visited.count(E.v1) && visited.count(E.v2)){ //边E的两端点已联通（在联通点集合中）
            continue;
        }
        else{
            T.push_back(E);
            visited.insert(E.v1);
            visited.insert(E.v2);
        }
    }
    for(auto E : T){
        E.show();
    }
    return 0;
}

/*

8 11
1 2 3
1 4 5
1 6 18
2 4 7
2 5 6
3 5 10
3 8 20
4 6 15
4 7 11
5 7 8
5 8 12

1 2 3
1 4 5
2 5 6
5 7 8
3 5 10
5 8 12
4 6 15


*/