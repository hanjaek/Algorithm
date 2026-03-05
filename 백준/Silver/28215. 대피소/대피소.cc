#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define endl "\n"
#define ll long long

int N, K;
vector<pair<ll, ll>> house;

ll dist(pair<ll ,ll> a, pair<ll, ll> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

void input(){
    cin >> N >> K;

    house.resize(N);

    for(ll i=0; i < N; i++){
        cin >> house[i].first >> house[i].second;
    }
}

void func(){
    if(K >= N){
        cout << 0 << endl;
        return;
    }
    
    ll result = 1e9;

    vector<ll> perm(N, 0);
    for(int i=N-K; i < N; i++){
        perm[i] = 1;
    }

    do{
        ll mx = 0;
        for(int i=0; i < N; i++){
            ll mn = 1e9;

            for(ll j=0; j < N; j++){
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