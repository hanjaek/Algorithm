#include <iostream>
#include <vector>

using namespace std;

int N, K;
string num;

void input(){
    cin >> N >> K;
    cin >> num;
}

void func(){
    vector<char> st;
    int del = K;

    for(char c : num){
        while(!st.empty() && del > 0 && st.back() < c){
            st.pop_back();
            del--;
        }
        st.push_back(c);
    }

    while(del > 0){
        st.pop_back();
        del--;
    }
    for(int i=0; i < N - K; i++){
        cout << st[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}