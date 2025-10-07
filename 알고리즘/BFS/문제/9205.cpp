#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n;
vector<pair<int, int>> place;
vector<bool> visited;

void input(){
    cin >> n;
    place.resize(n+2);
    visited.assign(n+2, false);

    for(int i=0; i < n+2; i++){
        cin >> place[i].first >> place[i].second;
    }
}

int dist(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool bfs(){
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == n+1) return true;

        for(int next = 0; next < n+2; next++){
            if(!visited[next] && dist(place[cur], place[next]) <= 1000){
                q.push(next);
                visited[next] = true;
            }
        }
    }
    return false;
}

void func(){
    cout << (bfs() ? "happy" : "sad") << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        input();
        func();
    }
}