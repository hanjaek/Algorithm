#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> m;
    vector<int> values;
    int sum = 0, answer = 0;
    
    for(int e : tangerine){
        m[e]++;
    }
    for(pair<int, int> p : m){
        values.push_back(p.second);
    }
    
    sort(values.begin(), values.end(), greater<int>());
    
    for(int cnt : values){
        sum += cnt;
        answer++;
        if(sum >= k) break;
    }
    
    return answer;
}