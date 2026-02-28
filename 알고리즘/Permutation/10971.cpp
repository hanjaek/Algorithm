#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N;
vector<vector<int>> W;

void input(){
    cin >> N;
    W.resize(N, vector<int>(N));

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            cin >> W[i][j];
        }
    }
}

void func(){
    int best_cost = 1e9;
    vector<int> visit;

    for(int i=0; i < N; i++){
        visit.push_back(i);
    }

    do{
        int cost = 0;
        bool valid = true;

        for(int i=0; i < N; i++){
            int from = visit[i];
            int to = visit[(i+1)%N];

            if(W[from][to] == 0){
                valid = false;
                break;
            }
            cost += W[from][to];
        }
        if(valid) best_cost = min(best_cost, cost);

    }while(next_permutation(visit.begin(), visit.end()));

    cout << best_cost << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
    return 0;
}