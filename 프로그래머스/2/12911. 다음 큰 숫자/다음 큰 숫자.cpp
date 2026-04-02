#include <bitset>

using namespace std;


// int binary_cnt(int n){
//     int result = 0;
    
//     while(n > 0){
//         if(n%2 == 1) result++;
//         n /= 2;
//     }
    
//     return result;
// }

int solution(int n) {
//     int answer = n+1;
//     int target_cnt = binary_cnt(n);

//     while(binary_cnt(answer) != target_cnt){
//         answer++;
//     }
    
//     return answer;
//========== 다른 풀이 ==========
    int target = bitset<20>(n).count();
    
    while(bitset<20>(++n).count() != target);
    return n;
}