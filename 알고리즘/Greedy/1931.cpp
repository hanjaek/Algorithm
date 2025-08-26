#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> meeting;

void input(){
    cin >> N;
    meeting.resize(N);
    for(int i=0; i < N; i++){
        int start, end;
        cin >> start >> end;
        meeting[i] = {start, end};
    }
}

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
} 

void func(){
    sort(meeting.begin(), meeting.end(), comp);

    int cnt = 0;
    int last = 0;

    for(auto[start, end] : meeting){
        if(start >= last){
            cnt++;
            last = end;
        }
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}