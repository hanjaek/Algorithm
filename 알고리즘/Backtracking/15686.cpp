#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> home, chicken;
vector<vector<int>> dist;
vector<int> selected;
int result = 1e9;

void input(){
    cin >> N >> M;

    for(int y=1; y <= N; y++){
        for(int x=1; x <= N; x++){
            int v;
            cin >> v;
            if(v==1) home.push_back({y, x});
            else if(v==2) chicken.push_back({y, x});
        }
    }
}

int calc_dist(){
    int sum = 0;

    for(int i=0; i < home.size(); i++){
        int best = 1e9;
        for(int c_idx : selected){
            best = min(best, dist[i][c_idx]);
        }
        sum += best;
        if(sum >= result) return sum;
    }
    return sum;
}

void dfs(int c_idx, int cnt){
    if(cnt == M){
        result = min(result, calc_dist());
        return;
    }

    if(c_idx == chicken.size()) return;
    // chicken.size() - c_idx -> 현재 남은 치킨집 (M보다 작으면 고를 치킨집 없음)
    if(cnt + (chicken.size() - c_idx) < M) return;

    selected.push_back(c_idx);
    dfs(c_idx + 1, cnt + 1);
    selected.pop_back();
    dfs(c_idx + 1, cnt);
}

void func(){
    dist.resize(home.size(), vector<int>(chicken.size(), 0));
    for(int i=0; i < home.size(); i++){
        for(int j=0; j < chicken.size(); j++){
            dist[i][j] = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
        }
    }

    dfs(0, 0);
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}