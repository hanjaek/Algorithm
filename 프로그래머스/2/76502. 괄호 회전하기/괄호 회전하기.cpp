#include <string>
#include <stack>

using namespace std;

bool is_right(string s){
    stack<char> st;
    
    for(char c : s){
        if(c == '(' || c == '[' || c == '{') st.push(c);
        else{
            if(st.empty()) return false;
            
            if(c == ')' && st.top() != '(') return false;
            if(c == ']' && st.top() != '[') return false;
            if(c == '}' && st.top() != '{') return false;
            
            st.pop();
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i < s.size(); i++){
        if(is_right(s)) answer++;
        s = s.substr(1) + s[0];
    }
    
    return answer;
}