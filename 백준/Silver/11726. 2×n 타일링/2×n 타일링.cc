#include <iostream>

using namespace std;

#define NUM 10007

int main(){

    // 점화식 : 마지막 타일을 체크하기
    // 마지막 타일의 모양 : 2x1 둘 or 1x2 하나 
    // 2x3인 경우 마지막이 2x1 둘이면 -> 앞은 1x2(1) -> DP[1], 1x2이면 -> 앞은 2x1(2) -> DP[2]

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int tile[1001]={0};

    tile[1] = 1 % NUM;
    tile[2] = 2 % NUM;
    cin >> n;

    for(int i=3; i <= n; i++){
        tile[i] = (tile[i-1] + tile[i-2]) % NUM;
    }

    cout << tile[n];

}