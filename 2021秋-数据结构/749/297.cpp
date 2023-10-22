#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    char s[81] = {0}; //str
    cin >> s;
    int n = strlen(s); //len
    int time = 1; //T
    bool flag = false; //have found min T?
    while(!flag && time <= n / 2){
        //for each T, flag = false
        int i = 0;
        int j = i + time;
        while(j < n){
            if(s[i] != s[j] || n % time != 0){
                flag = false;
                time++;
                break;
            }
            else{
                i++;
                j++;
                flag = true;
            }
        }
    }
    if(!flag){
        time = n;
    }
    cout << time << endl;
    return 0;
}

/*

GeeGeeGee
9

3

*/