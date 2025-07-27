#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> ropes;

void input(){
    cin >> N;
    ropes.resize(N);
    for(int i=0; i < N; i++){
        cin >> ropes[i];
    }
}

void func(){
    sort(ropes.begin(), ropes.end(), greater<>());

    int max_w = 0;

    for(int i=0; i < N; i++){
        int w = ropes[i] * (i+1);
        if(w > max_w){
            max_w = w;
        }
    }
    cout << max_w;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}