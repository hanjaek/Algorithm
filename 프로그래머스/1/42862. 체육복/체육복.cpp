#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> state(n+1, 1);
    
    for(int l : lost){
        state[l]--;
    }
    for(int r : reserve){
        state[r]++;
    }
    
    for(int i=2; i <= n; i++){
        if(!state[i-1] && state[i] == 2){
            state[i-1]++; state[i]--;
        }
        else if(state[i-1] == 2 && !state[i]){
            state[i-1]--; state[i]++;
        }
    }
    
    for(int i=1; i <= n; i++){
        if(state[i]){
            answer++;
        }
    }
    return answer;
}