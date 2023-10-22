#include <iostream>

using namespace std;

int max(int a, int b, int c = 0){
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int main(){
    cout << "max(114, 514)\n>>> " << max(114, 514) << endl;
    cout << "max(11, 45, 14)\n>>> " << max(11, 45, 14) << endl;
    return 0;
}