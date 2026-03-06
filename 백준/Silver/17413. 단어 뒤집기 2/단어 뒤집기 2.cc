#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

string S;

void input(){
    getline(cin, S);
}

void func(){
    string str = S;
    bool flag = false;
    string tmp = "";

    for(int i=0; i < str.size(); i++){
        if(str[i] == '<'){
            reverse(tmp.begin(), tmp.end());
            str.replace(i-tmp.size(), tmp.size(), tmp);
            tmp = "";
            flag = true;
        }
        else if(str[i] == '>'){
            flag = false;
        }
        else if(!flag){
            if(str[i] == ' '){
                reverse(tmp.begin(), tmp.end());
                str.replace(i-tmp.size(), tmp.size(), tmp);
                tmp = "";
            }
            else{
                tmp += str[i];
            }
        }
    }
    reverse(tmp.begin(), tmp.end());
    str.replace(str.size() - tmp.size(), tmp.size(), tmp);
    
    cout << str << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}