#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> numbers;
int op[4]; // +, -, *, /
int min_val = 1e9;
int max_val = -1e9;

void input(){
    cin >> N;
    numbers.resize(N);

    for(int i=0; i < N; i++){
        cin >> numbers[i];
    }
    for(int i=0; i < 4; i++){
        cin >> op[i];
    }
}

void dfs(int cur, int idx){
    if(idx == N){
        min_val = min(min_val, cur);
        max_val = max(max_val, cur);
        return;
    }

    for(int i=0; i < 4; i++){
        if(op[i] == 0) continue;
        op[i]--;

        int next_val;
        switch(i){
            case 0: next_val = cur + numbers[idx]; break;
            case 1: next_val = cur - numbers[idx]; break;
            case 2: next_val = cur * numbers[idx]; break;
            // 나눗셈 0처리도 하면 좋음
            case 3: next_val = cur / numbers[idx]; break; 
        }

        dfs(next_val, idx + 1);
        op[i]++;
    }
}

void func(){
    dfs(numbers[0], 1);
    cout << max_val << "\n";
    cout << min_val << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}