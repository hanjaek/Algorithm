#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> dist;
vector<long long> cost;

void input(){
    cin >> N;
    dist.resize(N-1);
    cost.resize(N);

    for(int i=0; i < N-1; i++){
        cin >> dist[i];
    }
    for(int i=0; i < N; i++){
        cin >> cost[i];
    }
}

void func(){
    long long total_cost = 0;
    long long min_cost = cost[0];

    for(int i=0; i < N-1; i++){
        min_cost = min(min_cost, cost[i]);
        total_cost += min_cost * dist[i];
    }

    cout << total_cost << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}