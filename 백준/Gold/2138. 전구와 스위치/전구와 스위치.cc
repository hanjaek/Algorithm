#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define endl "\n"

int N;
string state, target;

void switch_on(string &s, int idx){
    for(int i= idx-1; i <= idx+1; i++){
        if(0 <= i && i < N){
            s[i] = (s[i] == '0') ? '1' : '0'; 
        }
    }
}

int switch_simulation(string s, bool flag){
    int cnt = 0;

    if(flag){
        switch_on(s, 0);
        cnt++;
    }

    for(int i=1; i < N; i++){
        if(s[i-1] != target[i-1]){
            switch_on(s, i);
            cnt++;
        }
    }
    if(s == target) return cnt;
    return 1e9;
}

void input(){
    cin >> N;
    cin >> state;
    cin >> target;
}

void func(){
    int case1 = switch_simulation(state, true);
    int case2 = switch_simulation(state, false);
    int result = min(case1, case2);

    if(result == 1e9) cout << -1 << endl;
    else cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}