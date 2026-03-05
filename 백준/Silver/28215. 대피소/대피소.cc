#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define endl "\n"

int N, K;
vector<pair<int, int>> house;

int dist(pair<int ,int> a, pair<int, int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

void input(){
    cin >> N >> K;
    if(K >= N){
        cout << 0 << endl;
        return;
    }
    
    house.resize(N);

    for(int i=0; i < N; i++){
        cin >> house[i].first >> house[i].second;
    }
}

void func(){
    int result = 1e9;

    vector<int> perm(N, 0);
    for(int i=N-K; i < N; i++){
        perm[i] = 1;
    }

    do{
        int mx = 0;
        for(int i=0; i < N; i++){
            int mn = 1e9;

            for(int j=0; j < N; j++){
                if(perm[j]){
                    mn = min(mn, dist(house[i], house[j]));
                }
            }
            mx = max(mx, mn);
        }
        result = min(result, mx);
        
    }while(next_permutation(perm.begin(), perm.end()));

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}