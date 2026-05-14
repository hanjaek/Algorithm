#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int n = topping.size();
    
    unordered_map<int, int> lm, rm;
    // idx를 자른 위치 기준으로 -> 자른 횟수는 n-1회
    vector<int> left_cnt(n);
    vector<int> right_cnt(n);

    for(int cut=0; cut < n; cut++){
        lm[topping[cut]]++;
        rm[topping[n-1-cut]]++;
        
        left_cnt[cut] = lm.size();
        right_cnt[n-1-cut] = rm.size();
    }
    
    for(int i=0; i < n-1; i++){
        if(left_cnt[i] == right_cnt[i+1]) answer++;
        }
    
    return answer;
}