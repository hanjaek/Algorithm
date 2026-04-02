#include <string>
#include <vector>

using namespace std;

string to_binary(int n){
    if(n==0) return "0";
    string result = "";
    
    while(n > 0){
        result = char((n%2)+'0') + result;
        n /= 2;
    }
    return result;
}

int binary_cnt(string s){
    int result = 0;
    
    for(int i=0; i < s.size(); i++){
        if(s[i] == '1'){
            result++;
        }
    }
    return result;
}

int solution(int n) {
    int answer = n+1;
    string n_s = to_binary(n);
    int one_cnt = binary_cnt(n_s);

    while(true){
        string temp = to_binary(answer);
        int temp_cnt = binary_cnt(temp);
        
        if(temp_cnt == one_cnt) break;
        answer++;
    }
    
    return answer;
}