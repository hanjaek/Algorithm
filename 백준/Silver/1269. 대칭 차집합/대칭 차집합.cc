#include <iostream>
#include <set>

using namespace std;

int A_cnt, B_cnt;
set<int> A, B;

void input(){
    cin >> A_cnt >> B_cnt;

    int number;
    for(int i=0; i < A_cnt; i++){
        cin >> number;
        A.insert(number);
    }
    for(int i=0; i < B_cnt; i++){
        cin >> number;
        B.insert(number);
    }
}

void func(){
    int cnt = 0;
    for(int element : A){
        if(B.find(element) == B.end()) cnt++;
    }
    for(int element : B){
        if(A.find(element) == A.end()) cnt++;
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}