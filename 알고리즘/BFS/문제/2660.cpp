#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> E;
vector<int> dist;

void input(){
    cin >> N;
    E.resize(N+1);
    dist.resize(N+1, -1);

    while(1){
        int member1, member2;
        cin >> member1 >> member2;
        if(member1 == -1 && member2 == -1){
            break;
        }

        E[member1].push_back(member2);
        E[member2].push_back(member1);
    }
}

int bfs(int start){
    dist.assign(N+1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next : E[cur]){
            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    int score = 0;
    for(int i=1; i <= N; i++){
        if(dist[i] == -1) return 1e9;
        score = max(score, dist[i]);
    }
    return score;
}

void func(){
    vector<int> candidates;
    int min_score = 1e9;

    for(int i=1; i <= N; i++){
        int score = bfs(i);
        if(score < min_score){
            min_score = score;
            candidates.clear();
            candidates.push_back(i);
        }
        else if(score == min_score){
            candidates.push_back(i);
        }
    }

    cout << min_score << " " << candidates.size() << "\n";
    for(int member : candidates){
        cout << member << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}