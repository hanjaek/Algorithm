#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, x;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    while(N--){
        cin >> x;
        if(x==0){
            if(pq.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
    
}