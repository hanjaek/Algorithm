#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> perm;
    int d_cnt = dungeons.size();
    int answer = 0;
    
    for(int i=0; i < d_cnt; i++){
        perm.push_back(i);
    }
    
    do{
        int hp = k;
        int cnt = 0;
        
        for(int i=0; i < d_cnt; i++){
            int idx = perm[i];
            if(hp < dungeons[idx][0]) continue;
            
            hp -= dungeons[idx][1];
            cnt++;
        }
        answer = max(answer, cnt);
    }while(next_permutation(perm.begin(), perm.end()));
    
    return answer;
}