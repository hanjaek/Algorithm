#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
#define endl "\n"

int T, K;
string W;

// ======= 시간 초과 =======
// pair<int, int> part_string(string s){
//     if(K==1) return {1, 1};

//     int mn = 1e9;
//     int mx = -1;

//     for(int i=0; i < s.size(); i++){
//         char c = s[i];
//         int cnt = 1;

//         for(int j=i+1; j < s.size(); j++){
//             if(s[j] == c) cnt++;
//             if(cnt == K){
//                 mn = min(mn, j-i+1);
//                 mx = max(mx, j-i+1);
//                 break;
//             }
//         }
//     }

//     return {mn, mx};
// }
// ========================

pair<int, int> part_string(string s){
    vector<int> pos[26]; // a ~ z
    int mn = 1e9;
    int mx = -1;

    for(int i=0; i < s.size(); i++){
        pos[s[i] - 'a'].push_back(i);
    }

    for(int c=0; c < 26; c++){
        if(pos[c].size() < K) continue;

        for(int i=0; i+K-1 < pos[c].size(); i++){
            int len = pos[c][i+K-1] - pos[c][i] + 1;
            mn = min(mn, len);
            mx = max(mx, len);
        }
    }
    return {mn, mx};
}


void input(){
    cin >> W;
    cin >> K;
}

void func(){
    pair<int, int> result = part_string(W);

    if(result.second == -1){
        cout << -1 << endl;
    }
    else{
        cout << result.first << " " << result.second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while(T--){
        input();
        func();
    }
}