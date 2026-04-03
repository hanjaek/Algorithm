#include <string>

using namespace std;

long long solution(int n) {
    if(n==1) return 1;
    // DP 배열없이 구현 -> 피보나치
    long long a = 1;
    long long b = 2;
    
    for(int i=3; i <= n; i++){
        // DP[n] = DP[n-1] + DP[n-2];
        long long cur = (a + b) % 1234567;
        // 스왑
        a = b;
        b = cur;
    }
    
    return b;
}