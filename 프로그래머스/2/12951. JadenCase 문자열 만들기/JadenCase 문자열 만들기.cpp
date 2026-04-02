#include <string>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool first = true;
    
    for(int i=0; i < s.size(); i++){
        
        if(s[i] == ' '){
            answer += ' ';
            first = true;
        }
        else{
            if(first){
                answer += toupper(s[i]);
                first = false;
            }
            else{
                answer += tolower(s[i]);
            }
        }
    }
    return answer;
}