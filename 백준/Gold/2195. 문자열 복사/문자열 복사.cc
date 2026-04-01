#include <iostream>
#include <algorithm>

using namespace std;
#define endl "\n"

string S, P;

void input(){
    cin >> S;
    cin >> P;
}

void func(){
    int result = 0;
    int idx = 0;

    while(idx < P.size()){
        int best = 0;

        for(int i=0; i < S.size(); i++){
            int len = 0;

            while(i+len < S.size() && idx + len < P.size() && S[i+len] == P[idx+len]){
                len++;
            }
            best = max(best, len);
        }
        idx += best;
        result++;
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}