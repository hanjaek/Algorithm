#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N, L;
vector<int> leak;

void input(){
    cin >> N >> L;
    leak.resize(N);

    for(int i = 0; i < N; i++){
        cin >> leak[i];
    }

    sort(leak.begin(), leak.end());
}

void func(){
    int result = 0;
    int end_p = -1;

    for(int x : leak){
        if(end_p < x){
            result++;
            end_p = x + L - 1;
        }
    }

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}