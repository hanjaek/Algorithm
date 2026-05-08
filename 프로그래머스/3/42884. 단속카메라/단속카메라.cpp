#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int camera = - 300001;
    
    sort(routes.begin(), routes.end(), cmp);
    
    for(vector<int> route : routes){
        int in = route[0];
        int out = route[1];
        
        if(camera < in){
            answer++;
            camera = out;
        }
    }
    return answer;
}