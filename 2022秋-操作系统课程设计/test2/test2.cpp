#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

using namespace std;

int num = 114514;
mutex m;

void th(){
    cout << "th:\tstart" << endl;
    for(int i = 0; i < 10; i++){
        m.lock();
        cout << "th:\t" << num-- << endl;
        m.unlock();
        Sleep(1000);
    }
    cout << "th:\tend" << endl;
}

int main(){
    cout << "main:\tstart" << endl;
    thread t(th);
    for(int i = 0; i < 20; i++){
        m.lock();
        cout << "main:\t" << num-- << endl;
        m.unlock();
        Sleep(1000);
    }
    t.join();
    cout << "main:\tend" << endl;
}