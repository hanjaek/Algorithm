#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    int num;
    int mx = -1e9, mn = 1e9;
    
    while(ss >> num){
        mx = max(mx, num);
        mn = min(mn, num);
    }
    
    answer = to_string(mn) + " " + to_string(mx);
    
    return answer;
}