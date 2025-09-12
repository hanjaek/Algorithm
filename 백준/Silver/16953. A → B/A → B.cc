#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long A, B;

void input(){
    cin >> A >> B;
}

long long bfs(){
    queue<pair<long long, int>> q;
    q.push({A, 1});

    while(!q.empty()){
        auto [cA, step] = q.front();
        q.pop();

        if(cA == B) return step;

        long long nA1 = cA * 2;
        long long nA2 = cA * 10 + 1;

        if(nA1 <= B) q.push({nA1, step + 1});
        if(nA2 <= B) q.push({nA2, step + 1});
    }
    return -1;
}

void func(){
    cout << bfs();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}