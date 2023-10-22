#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Stack{
public:
    int st[100];
    int top;
    Stack(){
        memset(st, 0, sizeof(st));
        top = 0;
    }
    void push(int i){
        st[top++] = i;
    }
    int pop(){
        return st[--top];
    }
    int topElem(){
        return st[top - 1];
    }
    bool isEmpty(){
        return top == 0;
    }
};

vector<string> split(const char *str, const char* delim){
	vector<string> res;

	if(str == ""){
        return res;
    }

	//先将要切割的字符串从string类型转换为char*类型
	char *strs = new char[strlen(str)];
	strcpy(strs, str);

	char *p = strtok(strs, delim);
	while(p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, delim);
	}

    /*
    string sub;
    char *strs = new char[strlen(str)];
	strcpy(strs, str);
    char *p = strs;
    while(*p != '\0'){
        while(*p != delim){
            sub += *p;
            p++;
        }
        res.push_back(sub);
        sub = "";
        p++;
    }
    */

	return res;
}

bool isInteger(const string s){
    for (char const &c : s) {
        if (isdigit(c) == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]){
    char str[100] = {0};
    cin.get(str,100);
    vector<string> elem = split(str, " ");
    Stack s;
    int a, b;
    string sub;
    for(auto it = elem.rbegin(); it != elem.rend(); ++it){
        sub = *it;
        if(isInteger(sub)){
            s.push(atoi(sub.c_str()));
        }
        else{
            a = s.pop();
            b = s.pop();
            switch((sub.data())[0]){
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    cout << s.pop() << endl;
    return 0;
}

/*

+ * + 42 8 – 36 6 / 9 3
+ * + 42 8 - 36 6 / 9 3

1503

*/