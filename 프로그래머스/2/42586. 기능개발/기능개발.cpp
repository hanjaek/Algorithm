#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Jobs{
    int progresse;
    int speed;
};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<Jobs> q;
    int s = progresses.size();
    
    for(int i=0; i < s; i++){
        q.push({progresses[i], speeds[i]});
    }
    
    while(!q.empty()){
        int cnt = 0;
        int q_s = q.size();
        
        for(int i=0; i < q_s; i++){
            Jobs cur = q.front(); q.pop();
            
            cur.progresse += cur.speed;
            q.push(cur);
        }
        
        while(!q.empty() && q.front().progresse >= 100){
            q.pop();
            cnt++;
        }
        if(cnt) answer.push_back(cnt);
    }
    
    return answer;
}