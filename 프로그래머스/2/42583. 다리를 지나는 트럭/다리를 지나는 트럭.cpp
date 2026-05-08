#include <string>
#include <vector>
#include <queue>

using namespace std;

void init_state(queue<int> &state, int n){
    for(int i=0; i < n; i++){
        state.push(0);
    }
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> state;
    int answer = 0;
    int cur_w = 0;
    int idx = 0;
    
    init_state(state, bridge_length);
    
    while(idx < truck_weights.size()){
        cur_w -= state.front();
        state.pop();
        
        if(cur_w + truck_weights[idx] <= weight){
            state.push(truck_weights[idx]);
            cur_w += truck_weights[idx];
            idx++;
        }
        else{
            state.push(0);
        }
        answer++;
    }
    answer += bridge_length;
        
    return answer;
}