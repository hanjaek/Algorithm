#include <iostream>
#include <deque>

using namespace std;

int N;
deque<pair<int, int>> dq;

void input(){
    cin >> N;
    for(int i=1; i <= N; i++){
        int num;
        cin >> num;
        dq.push_back({i, num});
    }
}

void func(){
    while(!dq.empty()){
        int idx = dq.front().first;
        int move = dq.front().second;
        dq.pop_front();
        cout << idx << " ";

        if(dq.empty()) break;

        if(move > 0){
            for(int i=0; i < move - 1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            for(int i=0; i < -move; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}