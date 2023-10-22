#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int value;
    Node *lchild;
    Node *rchild;

    Node(int v){
        value = v;
        lchild = NULL;
        rchild = NULL;
    }
};

int childron = 0;
void getChildron(Node *node){
    ++childron;
    if(node ->lchild != NULL){
        getChildron(node ->lchild);
    }
    if(node ->rchild != NULL){
        getChildron(node ->rchild);
    }
}

class PBTree{
public:
    Node *root;
};

int main(int argc, char* argv[]){
    int m, n;
    while(true){
        cin >> m >> n;
        if(m == 0 && n == 0){
            break;
        }
        queue<Node> q;
        PBTree t;
        Node *target;
        q.push(*t.root);
        int i = 1;
        while(true){
            Node node = q.front();
            q.pop();
            node.lchild = new Node(i++);
            q.push(*node.lchild);
            if(i - 1 == m){
                target = node.lchild;
            }
            if(i > n){
                break;
            }
            node.rchild = new Node(i++);
            q.push(*node.rchild);
            if(i - 1 == m){
                target = node.lchild;
            }
            if(i > n){
                break;
            }
        }
        getChildron(target);
        cout << childron << endl;
    }
    return 0;
}

/*

3 12
0 0

4

*/