#include <iostream>
#include <vector>

using namespace std;
#define endl "\n"

int k, s;
string S;

string trans_crypto(string str){
    string trans_str = str;
    int shift = k % 26; // a~z || A~Z : 26

    for(char &c : trans_str){
        if('a' <= c && c <= 'z'){
            c = char('a' + (c - 'a' + shift) % 26);
        }
        else if('A' <= c && c <= 'Z'){
            c = char('A' + (c - 'A' + shift) % 26);
        }
    }
    return trans_str;
}

void input(){
    cin >> k >> s;
    cin.ignore();
    getline(cin, S);
}

void func(){
    string result = trans_crypto(S);
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}