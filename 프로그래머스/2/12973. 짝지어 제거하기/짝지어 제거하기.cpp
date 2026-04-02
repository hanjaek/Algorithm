#include <iostream>
// #include <stack>
using namespace std;

int solution(string s)
{
//     stack<char> st;
    
//     for(char c : s){
//         if(!st.empty() && st.top() == c){
//             st.pop();
//         }
//         else st.push(c);
//     }
    
//     return (st.empty() ? 1 : 0);
    
//  ========== 다른 풀이 ==========
    int idx = 0;
    
    for(char c : s){
        if(idx > 0 && s[idx-1] == c){
            idx--;
        }
        else{
            s[idx] = c;
            idx++;
        }
    }
    return !idx;
}