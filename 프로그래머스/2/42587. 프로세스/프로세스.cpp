#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process{
    int idx;
    int priority;
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<Process> q;
    
    for(int i=0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
    }
    
    while(!q.empty()){
        Process cur = q.front();
        q.pop();
        
        bool is_higher = false;

        for(int p : priorities){
            if(p > cur.priority){
                is_higher = true;
                break;
            }
        }
        
        if(is_higher){
            q.push(cur);
        }else{
            answer++;        
            if(cur.idx == location) return answer;
            
            auto it = find(priorities.begin(), priorities.end(), cur.priority);
            priorities.erase(it);
        }
    }
    
    return answer;
}