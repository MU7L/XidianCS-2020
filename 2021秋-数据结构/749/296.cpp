#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    char str[100] = {0};
    int n = 0;
    cin >> n >> str;
    //cout << str << endl;
    char *front = str;
    char *back = str + sizeof(char) * (n - 1);
    //cout << *front << ' ' << *back << endl;
    string ans = "YES";
    while(front < back){
        if(*front != *back){
            ans = "NO";
            break;
        }
        ++front;
        --back;
    }
    cout << ans << endl;
    return 0;
}