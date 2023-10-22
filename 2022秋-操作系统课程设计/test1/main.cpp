#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;

int main(int argc, char* argv[]){
    STARTUPINFO si = {0};
    ZeroMemory(&si, sizeof(STARTUPINFO));
    PROCESS_INFORMATION pi = {0};
    if(CreateProcess( 
        TEXT("D:\\code\\Cpp\\os\\test1\\sub_process.exe"),
        NULL,
        NULL,
        NULL,
        false,
        CREATE_NEW_CONSOLE,
        NULL,
        NULL,
        &si,
        &pi
        )
    ){
        cout << "main:\tsuccessfully create process" << endl;
        WaitForSingleObject(pi.hProcess, INFINITE);
        cout << "main:\tend" << endl;
    }
    else{
        cout << "main:\tcreating process failed" << endl;
    }

}