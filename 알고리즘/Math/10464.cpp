#include <iostream>

using namespace std;

/*
XOR은 각 비트의 1의 개수가 홀수면 1, 짝수면 0
--> 1~n까지의 XOR은 규칙이 존재
--> but, 임의의 숫자 m, m~n까지는 적용 x
--> 이럴땐 XOR(m) - XOR(n-1)
--> ex) m=4, n=12 -> XOR(12) - XOR(3)
-->                  1~12까지 - 1~3까지 = 4~12까지

n까지
1. n=1 -> 0001 -> 1
2. n=2 -> 0001 ^ 0010 -> 0011 : 3
3. n=3 -> 0001 ^ 0010 ^ 0011 -> 0000 : 0
4. n=4 -> 1^2^3^4 - > 0100 : 4
5. n=5 -> 0100(n=4값) ^ 0101 -> 0001 : 1
6. n=6 -> 0001 ^ 0110 -> 0111 : 7
7. n=7 -> 0111 ^ 0111 -> 0000 : 0
8. n=8 -> 0000 ^ 1000 -> : 1000 : 8

1-> 1 -- n % 4 = 1 ------ n % 4 = 1
2-> 3 -- n % 4 = 2 ------ n % 4 = n + 1
3-> 0 -- n % 4 = 3 ------ n % 4 = 0
4-> 4 -- n % 4 = 0 ------ n % 4 = n
5-> 1 -- n % 4 = 1------- n % 4 = 1
6-> 7 -- n % 4 = 2 ------ n % 4 = n + 1
7-> 0 -- n % 4 = 3 ------ n % 4 = 0
8-> 8 -- n % 4 = 0 ------ n % 4 = n

*/

int T;
int S, F;

void input(){
    cin >> T;
}

int XOR(int n){
    if(n < 0) return 0;
    switch(n % 4){
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0;
}

void func(){
    while(T--){
        cin >> S >> F;
        int result = XOR(F) ^ XOR(S-1);
        cout << result << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}