#include <iostream>
#include <string>

using namespace std;

string S;

void input(){
    cin >> S;
}

void func(){
    int idx = 0;
    int i = 1;

    while(true){
        string num = to_string(i);
        for(char c : num){
            if(c == S[idx]){
                idx++;
                if(idx == S.length()){
                    cout << i;
                    return;
                }
            }
        }
        i++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}