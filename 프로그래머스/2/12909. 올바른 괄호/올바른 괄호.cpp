#include <iostream>
// #include <stack>

using namespace std;

bool solution(string s)
{
//     bool answer = true;
//     stack<char> st;
    
//     for(char c : s){
//         if(c == ')'){
//             if(st.empty()) return false;
//             st.pop();
//         }else{
//             st.push(c);
//         }
//     }
//     if(!st.empty()) answer = false;
    
//     return answer;
// =========== 다른 풀이 ===========
    int n = 0;
    for(int i=0; i < s.size(); i++){
        if(n < 0) return false;
        
        if(s[i] == '(') n++;
        else n--;
    }
    return n == 0;
}