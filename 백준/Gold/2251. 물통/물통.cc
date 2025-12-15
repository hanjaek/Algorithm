#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int bottle[3];
bool visited[201][201];
bool possible[201];

int froms[6] = {0, 0, 1, 1, 2, 2};
int tos[6] = {1, 2, 0, 2, 0, 1};

void input(){
    cin >> bottle[0] >> bottle[1] >> bottle[2];
}

void bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        int state[3];
        state[0] = a;
        state[1] = b;
        state[2] = bottle[2] - a - b;

        if(state[0] == 0) possible[state[2]] = true;

        for(int d=0; d < 6; d++){
            int from = froms[d];
            int to = tos[d];
            int next[3] = {state[0], state[1], state[2]};

            int move = min(next[from], bottle[to] - next[to]);
            next[from] -= move;
            next[to] += move;

            int na = next[0];
            int nb = next[1];

            if(!visited[na][nb]){
                q.push({na, nb});
                visited[na][nb] = true;
            }
        }
    }
}

void func(){
    vector<int> result;

    bfs();

    for(int p=0; p <= bottle[2]; p++){
        if(possible[p]) result.push_back(p);
    }
    sort(result.begin(), result.end());

    for(int i=0; i < result.size(); i++){
        cout << result[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}