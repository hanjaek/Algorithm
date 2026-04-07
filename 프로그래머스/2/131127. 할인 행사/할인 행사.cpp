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
    int need_day = 0;
    int answer = 0;
    
    for(int num : number) need_day += num;
    for(int i = 0; i <= discount.size() - need_day; i++){
        unordered_map<string, int> m;
        for(int j = i; j < i + need_day; j++){
            m[discount[j]]++;
        }
        if(check_item(want, number, m)){
            answer++;
        }
    }
    return answer;
}