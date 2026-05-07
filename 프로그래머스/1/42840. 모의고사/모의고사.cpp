#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int student_1[5] = {1, 2, 3, 4, 5};
int student_2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int student_3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    int cnt[3] = {0};
    vector<int> answer;
    
    for(int i=0; i < answers.size(); i++){
        int cur = answers[i];
        
        if(cur == student_1[i%5]) cnt[0]++;
        if(cur == student_2[i%8]) cnt[1]++;
        if(cur == student_3[i%10]) cnt[2]++;
    }
    int mx = *max_element(cnt, cnt+3);
    
    for(int i=0; i < 3; i++){
        if(cnt[i] == mx){
            answer.push_back(i+1);
        }
    }
    return answer;
}