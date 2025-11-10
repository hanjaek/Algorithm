#include <iostream>
#include <algorithm>

using namespace std;

string S;

void input(){
    cin >> S;
}

void func(){
    bool flag = false;
    long long sum = 0;

    for (char c : S) {
        if (c == '0') flag = true;
        sum += (c - '0');
    }

    if (!flag || sum % 3 != 0) {
        cout << -1 << "\n";
        return;
    }

    sort(S.rbegin(), S.rend());
    cout << S << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    func();
}