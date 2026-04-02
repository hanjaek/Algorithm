#include <string>
#include <vector>

using namespace std;

string to_binary(int n){
    if(n == 0) return "0";
    string result = "";
    
    while(n > 0){
        result = char((n % 2) + '0') + result;
        n /= 2;
    }
    return result;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(s.size() > 1){
        string temp = "";
        for(char c : s){
            if(c == '1'){
                temp += c;
            }
        }
        int t_size = temp.size();
        answer[1] += (s.size() - t_size);

        s = to_binary(t_size);
        answer[0]++;
    }
    
    return answer;
}