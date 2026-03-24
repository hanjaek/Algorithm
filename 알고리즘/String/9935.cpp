#include <iostream>
#include <vector>

using namespace std;
#define endl "\n"

string S, bomb;

void input(){
    cin >> S;
    cin >> bomb;
}

void func(){
    string result = "";
    int b_len = bomb.size();

    for(char ch : S){
        result += ch;

        if(result.size() >= b_len){
            bool flag = true;

            for(int i=0; i < b_len; i++){
                if(result[result.size() - b_len + i] != bomb[i]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                for(int i=0; i < b_len; i++){
                    result.pop_back();
                }
            }
        }
    }
    cout << (result.empty() ? "FRULA" : result) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}