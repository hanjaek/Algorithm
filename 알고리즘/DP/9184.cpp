#include <iostream>

using namespace std;

int dp[21][21][21];
int a, b, c;

int w(int a, int b, int c){
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

    int &result = dp[a][b][c];
    if(result != 0) return result;

    if(a < b && b < c){
        result = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else{
        result = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    return result;
}

void func(){
    int result = w(a, b, c);
    cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
}

void input(){
    while(true){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        func();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
}