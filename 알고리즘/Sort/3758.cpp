#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// n: 팀 개수, k: 문제 개수, t: 내 팀 ID, m: 정보 수 
int T, n, k, t, m;
// 튜플은 총점, 제출횟수, 마지막제출 (인덱스가 팀 ID로)
vector<tuple<int, int, int>> teams;
vector<vector<int>> best;

void input(){
    cin >> n >> k >> t >> m;
    teams.assign(n+1, {0, 0, 0});
    best.assign(n+1, vector<int>(k+1, 0));

    for(int submit=1; submit <= m; submit++){
        int id, j, s;
        cin >> id >> j >> s;

        get<1>(teams[id])++;
        get<2>(teams[id]) = submit;

        int pre_s = best[id][j];
        if(s > pre_s){
            best[id][j] = s;
            get<0>(teams[id]) += (s - pre_s);
        }
    }
}

void func(){
    vector<tuple<int, int, int, int>> rank;
    rank.resize(n);

    for(int id=1; id <= n; id++){
        rank[id-1] = {id, get<0>(teams[id]), get<1>(teams[id]), get<2>(teams[id])};
    }

    sort(rank.begin(), rank.end(), [](const auto& a, const auto& b){
        if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
        if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
        return get<3>(a) < get<3>(b);
    });

    for(int i=0; i < n; i++){
        if(get<0>(rank[i]) == t){
            cout << i + 1 << "\n";
            return;
        }
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