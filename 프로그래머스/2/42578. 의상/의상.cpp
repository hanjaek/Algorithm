#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// int comb[31][31];

// void make_comb(){
//     for(int i=0; i < 31; i++){
//         comb[i][0] = comb[i][i] = 1;
        
//         for(int j=1; j < i; j++){
//             comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
//         }
//     }
// }

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> m;
    int answer = 1;
    
    for(vector<string> s : clothes){
        m[s[1]]++;
    }
    
    for(pair<string, int> p : m){
        answer *= (p.second + 1);
    }
    
    return answer - 1;
}