#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

bool check_end_word(string a, string b){
    return a.back() == b.front();
}

vector<int> solution(int n, vector<string> words) {
    unordered_map<string, int> m;
    vector<int> answer = {0, 0};
    m[words[0]] = 1;
    
    for(int i=1; i < words.size(); i++){
        if(m[words[i]] || !check_end_word(words[i-1], words[i])){
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            return answer;
        }
        m[words[i]]++;
    }
    
    return answer;
}