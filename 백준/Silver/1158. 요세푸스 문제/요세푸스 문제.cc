#include <iostream>
#include <queue>

using namespace std;

int N, K;

void input(){
    cin >> N >> K;
}

void func(){
    queue<int> q;
    for(int i=1; i <= N; i++){
        q.push(i);
    }

    cout << "<";
    while(!q.empty()){
        for(int i=0; i < K-1; i++){
            int number = q.front();
            q.push(number);
            q.pop();
        }
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    cout <<">";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}