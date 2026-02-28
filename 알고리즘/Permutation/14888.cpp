#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N;
vector<int> numbers;
int op_cnt[4];

void calc(int &a, int b, int op){
    switch(op){
        case 0: a = a + b; break;
        case 1: a = a - b; break;
        case 2: a = a * b; break;
        case 3: a = a / b; break;
    }
}

void input(){
    cin >> N;
    numbers.resize(N);

    for(int i=0; i < N; i++){
        cin >> numbers[i];
    }

    for(int i=0; i < 4; i++){
        cin >> op_cnt[i];
    }
}

void func(){
    vector<int> ops;
    int mn = 1e9;
    int mx = -1e9;

    for(int i=0; i < op_cnt[0]; i++) ops.push_back(0);
    for(int i=0; i < op_cnt[1]; i++) ops.push_back(1);
    for(int i=0; i < op_cnt[2]; i++) ops.push_back(2);
    for(int i=0; i < op_cnt[3]; i++) ops.push_back(3);

    do{
        int val = numbers[0];

        for(int i=0; i < N-1; i++){
            int next = numbers[i+1];
            int op = ops[i];

            calc(val, next, op);
        }
        mx = max(mx, val);
        mn = min(mn, val);

    }while(next_permutation(ops.begin(), ops.end()));

    cout << mx << endl << mn << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}