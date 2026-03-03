#include <iostream>
#include <vector>
#include <cctype>

using namespace std;
#define endl "\n"

int N;
vector<string> S;

void to_lower(string &s){
    for(int i=0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }
}

void input(){
    cin >> N;
    S.resize(N);

    for(int i=0; i < N; i++){
        cin >> S[i];
    }
}

void func(){
    for(int i=0; i < S.size(); i++){
        to_lower(S[i]);
        cout << S[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}