#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> fruit;
vector<int> cnt(10,0);

void input(){
    cin >> N;
    fruit.resize(N);
    for(int i=0; i < N; i++){
        cin >> fruit[i];
    }
}

void func(){
    int left = 0, right = 0, total_type = 0;
    int result = 0;

    while(right < N){
        if(cnt[fruit[right]]++ == 0) total_type++;

        while(total_type > 2){
            if(--cnt[fruit[left]] == 0) total_type--;
            left++;
        }

        result = max(result, right - left + 1);
        right++;
    }

    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}