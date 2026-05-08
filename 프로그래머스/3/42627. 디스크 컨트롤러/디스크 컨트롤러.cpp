#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process{
    int idx;
    int req_time;
    int job_time;
    
    bool operator<(const Process &other) const{
        if(job_time == other.job_time){
            if(req_time == other.req_time){
                return idx > other.idx;
            }
            else return req_time > other.req_time;
        }
        else return job_time > other.job_time;
    }
};

int solution(vector<vector<int>> jobs) {
    priority_queue<Process> pq;
    int cur_time = 0;
    int total_time = 0;
    int idx = 0;
    int done = 0;
    int n = jobs.size();
    
    sort(jobs.begin(), jobs.end());
    
    while(done< n){
        
        while(idx < n && jobs[idx][0] <= cur_time){
            pq.push({idx, jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        
        if(!pq.empty()){
            Process cur = pq.top();
            pq.pop();

            cur_time += cur.job_time;
            total_time += (cur_time - cur.req_time);
            done++;
        }
        else{
            cur_time = jobs[idx][0];
        }
    }
    
    return (total_time / jobs.size());
}