#include <iostream>
#include <cstring>

using namespace std;

void func(char *str) {
	char track[100] = {0};
	int i = 0, t = 0, is = 1, len = strlen(str);
	while(i < len){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
			track[t++] = str[i];
		}
		else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
			if(str[i] == ')' && track[t-1] == '('){
				goto deal;
			}
			else if(str[i] == ']' && track[t-1] == '['){
				goto deal;
			}
			else if(str[i] == '}' && track[t-1] == '{'){
deal:
				track[--t]='\0';
				i++;
				continue;
			}
			else{
				is = 0;
				break;
			}
		}
		i++;
	}
	if(strcmp(track, "\0") != 0){
		is = 0;
	}
	if(is == 1)
		printf("right");
	else
		printf("wrong");
}

int main(int argc, char* argv[]){
    char str[100] = {0};
    cin.get(str, 100);
    func(str);
    return 0;
}

/*

while (m<(a[8]+t) {m=m+1;  t=t-1;}

wrong

*/