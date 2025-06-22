#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int N, K;
int visited_time[MAX];

void input(){
    cin >> N >> K;
}

void bfs(int start, int target){
    queue<int> q;
    q.push(start);
    visited_time[start] = 1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == target){
            // 일부러 방문 여부 및 시간 누적을 함께 사용하기 위해 시작 시간을 1부터 시작했음
            cout << visited_time[cur] -1; 
            return;
        }

        for(int next : {cur -1, cur +1, cur *2}){
            if(next >= 0 && next < MAX && visited_time[next]==0){
                visited_time[next] = visited_time[cur] + 1;
                q.push(next);
            }
        }
    }
}

void func(){
    bfs(N, K);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}