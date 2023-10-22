#include <iostream>

using namespace std;

int puzzle[100][100] = {0}; //地图 0=可走 1=墙 2=已走过；

class Node{
public:
    int m;      //行
    int n;      //列
    int direct; //下一步方向
    Node *prior;
    Node(){
        m = 0;
        n = 0;
        direct = 0;
        prior = NULL;
    }
    Node(int posM, int posN, int dir){
        m = posM;
        n = posN;
        direct = dir;
        prior = NULL;
    }
    void print(){
        if(prior != NULL){
            prior -> print();
        }
        cout << "(" << m << "," << n << "," << direct << "),";
    }
    void directPrint(){
        cout << "(" << m << "," << n << "," << direct << ")";
    }
};

class Stack{
public:
    Node *end;
    Stack(){
        end = NULL;
    }
    void push(Node *node){
        node -> prior = end;
        end = node;
    }
    void pop(){
        Node *del = end;
        end = end -> prior;
        delete del;
    }
    void print(){
        if(isEmpty()){
            return;
        }
        end -> print();
    }
    bool isEmpty(){
        return end == NULL;
    }
};

class Man{
public:
    int m;
    int n;
    Man(Node *pos){
        m = pos -> m;
        n = pos -> n;
    }
    void move(int direct){ //原地标记再移动
        paint(2);
        switch(direct){
            case 1: n++; break;
            case 2: m++; break;
            case 3: n--; break;
            case 4: m--; break;
        }
        paint(8); //test
    }
    int nextMove(int direct){
        int rtn = 0;
        switch(direct){
            case 1: rtn = puzzle[m][n + 1]; break;
            case 2: rtn = puzzle[m + 1][n]; break;
            case 3: rtn = puzzle[m][n - 1]; break;
            case 0:
            case 4: rtn = puzzle[m - 1][n]; break;
        }
        return rtn;
    }
    void paint(int flag){
        puzzle[m][n] = flag;
    }
};

int reverseDirect(int direct){
    return (direct + 2) % 4;
}

void showInfo(Stack *s){
    cout << "\n";
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << puzzle[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    s -> print();
    cout << "\n" << endl;
}

//无解判断？
int main(int argc, char* argv[]){
    //puzzle初始化
    int height = 0;
    int width = 0;
    cin >> height >> width;
    Node startNode, endNode;
    cin >> startNode.m >> startNode.n >> endNode.m >> endNode.n;
    endNode.direct = 1;
    Stack step;
    for(int j = 0; j <= width + 1; j++){
        puzzle[0][j] = 1; //上围栏
    }
    for(int i = 1; i <= height; i++){
        puzzle[i][0] = 1; //左围栏
        for(int j = 1; j <= width; j++){
            cin >> puzzle[i][j];
        }
        puzzle[i][width + 1] = 1; //右围栏
    }
    for(int j = 0; j <= width + 1; j++){
        puzzle[height + 1][j] = 1; //围栏
    }
    Man man(&startNode);
    //寻路
    int op = 1;
    int nextPos = 0;
    while(man.m != endNode.m || man.n != endNode.n){ //一层循环只前进1步
        nextPos = man.nextMove(op);
        while(nextPos == 1 || nextPos == 2){ //四方向寻路 不通进入循环 通行跳出
            op++;
            while(op > 4){ //死路回退 先回退 再出栈
                if(step.isEmpty()){
                    goto FAIL;
                }
                op = step.end -> direct;
                man.move(reverseDirect(op));
                op++;
                step.pop();
                //showInfo(&step); //test
            }
            nextPos = man.nextMove(op);
        }
        if(nextPos == 0){ //当前位置入栈 再通行

            step.push(new Node(man.m, man.n, op));
            man.move(op);
            op = 1;
            //showInfo(&step); //test
        }
    }
    //结束
    step.print();
    endNode.directPrint();
    return 0;
FAIL:
    cout << "no" << endl;
    return 0;
}

/*
8 8
1 1
8 8
0 0 1 0 0 0 1 0
0 0 1 1 0 0 1 0
0 0 0 0 1 1 0 0
0 1 1 1 0 0 0 0
0 0 0 1 1 0 0 0
0 1 0 0 0 1 0 0
0 1 1 1 0 1 1 0
1 1 0 0 0 0 0 0

(1,1,1),(1,2,2),(2,2,2),(3,2,3),(3,1,2),(4,1,2),(5,1,1),(5,2,1),(5,3,2),(6,3,1),(6,4,1),(6,5,2),(7,5,2),(8,5,1),(8,6,1),(8,7,1),(8,8,1)

2 3
1 1
2 3
0 0 1
1 1 0

no

2 2
1 1
2 2
0 1
1 0

no

1 2
1 1
1 2
0 0

(1,1,1),(1,2,1)

1 1
1 1
1 1
0
(1,1,1)
*/