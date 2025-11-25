#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> S, B;
int result = 1e9;

void input(){
    cin >> N;
    S.resize(N); B.resize(N);

    for(int i=0; i < N; i++){
        cin >> S[i] >> B[i];
    }
}
/*

예시로 N=3일 때,

mask(십진수)	mask(2진수)	  의미
0	           000	        아무 것도 선택 X
1	           001         	0번 선택
2	           010      	1번 선택
3	           011	        0번,1번 선택
4	           100	        2번 선택
5	           101	        0번,2번 선택
6	           110	        1번,2번 선택
7              111	        0,1,2 선택

*/
void func(){
    for(int mask = 1; mask < (1 << N); mask++){
        int prod = 1;
        int sum = 0;

        for(int i=0; i < N; i++){
            if(mask & (1 << i)){
                prod *= S[i];
                sum += B[i];
            }
        }
        int diff = abs(prod - sum);
        result = min(result, diff);
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}