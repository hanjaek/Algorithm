#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A, B;

void input(){
    cin >> A >> B;
}

void func(){
    int min_cnt = 51;

    for(int i=0; i <= B.length() - A.length(); i++){
        int cnt = 0;
        for(int j=0; j < A.length(); j++){
            if(A[j] != B[i+j]) cnt++;
        }
        min_cnt = min(min_cnt, cnt);
    }
    cout << min_cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}