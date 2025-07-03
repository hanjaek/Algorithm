#include <iostream>
#include <string>

using namespace std;

string str;

void input(){
    cin >> str;
}

void func(){
    int zero = 0, one = 0;
    if(str[0]=='0') zero++;
    else one++;

    for(int i=1; i < str.length(); i++){
        if(str[i] != str[i-1]){
            if(str[i]=='0') zero++;
            else one++;
        }
    }

    cout << min(zero, one);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}