#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool check_item(vector<string> want, vector<int> number, unordered_map<string, int> m){
    for(int i=0; i < want.size(); i++){
        if(m[want[i]] != number[i]) return false;
    }
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> m;
    
    for(int i=0; i < 10; i++){
        m[discount[i]]++;
    }
    if(check_item(want, number, m)) answer++;
    
    for(int i=10; i < discount.size(); i++){
        m[discount[i-10]]--;
        m[discount[i]]++;
        
        if(check_item(want, number, m)) answer++;
    }
    
    return answer;
}