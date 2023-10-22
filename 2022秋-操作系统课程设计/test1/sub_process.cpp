#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){
    fstream ifs;
    ifs.open("file.txt", ios::in);
    if(!ifs.is_open()){
        cout << "ifs failed" << endl;
    }
    else{
        string buf;
        getline(ifs, buf);
        cout << "sub:\t" << buf << endl;
    }
    system("pause");
    return 0;
}