#include <iostream>
#include <queue>

using namespace std;

int main(){

    int T, M, N; //T: 테스트 수; M: 문서 수; N: 찾으려는 문서 인덱스(0부터)
    cin >> T;
    for(int i=0; i < T; i++){
        cin >> M >> N;
        
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int cnt = 0;

        for(int j=0; j < M; j++){
            int priority;
            cin >> priority;
            q.push({priority, j});
            pq.push(priority);
        }

        while(!q.empty()){
            int cur_p = q.front().first;
            int cur_idx = q.front().second;
            q.pop();

            if(cur_p < pq.top()){
                q.push({cur_p, cur_idx});
            }
            else{
                pq.pop();
                cnt++;
                if(cur_idx == N){
                    cout << cnt << "\n";
                    break;
                }
            }
        }
    }
}