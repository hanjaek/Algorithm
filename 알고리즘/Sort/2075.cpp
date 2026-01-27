#include <iostream>
#include <vector>
#include <queue>

#define endl "\n"
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

void input(){
    cin >> N;
}

void func(){
    for(int i=0; i < N*N; i++){
        int x;
        cin >> x;
        pq.push(x);

        if(pq.size() > N) pq.pop();
    }

    cout << pq.top() << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}