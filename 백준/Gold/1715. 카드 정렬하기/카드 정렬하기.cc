#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int N;
priority_queue<long long, vector<long long>, greater<>> pq;
// 주석 : 반복마다 sort때문에 시간초과
// vector<long long> v;

// void input(){
//     cin >> N;
//     v.resize(N);

//     for(int i=0; i < N; i++){
//         cin >> v[i];
//     }
// }

// void func(){
//     long long result = 0;
//     if(N==1) cout << 0;

//     while(v.size() > 1){
//         sort(v.begin(), v.end());

//         long long min1 = v[0];
//         long long min2 = v[1];

//         result += min1 + min2;

//         v.erase(v.begin());
//         v.erase(v.begin());
//         v.push_back(min1 + min2);
//     }

//     cout << result;
// }

void input(){
    cin >> N;

    for(int i=0; i < N; i++){
        long long card;
        cin >> card;
        pq.push(card);
    }
}

void func(){
    long long result = 0;

    if(N==1){
        cout << 0 << "\n";
        return;
    }

    while(pq.size() > 1){
        long long min1 = pq.top(); pq.pop();
        long long min2 = pq.top(); pq.pop();
        result += min1 + min2;
        pq.push(min1 + min2);
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}