#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define endl "\n"

struct cmp{
    bool operator()(const long long &a, const long long &b) const {
        return a > b;
    }
};
int N, M;
priority_queue<long long, vector<long long>, cmp> pq;

void input(){
    cin >> N >> M;
    for(int i=0; i < N; i++){
        int num;
        cin >> num;

        pq.push(num);
    }
}

void func(){
    long long result = 0;

    for(int i=0; i < M; i++){
        long long min_num1 = pq.top(); pq.pop();
        long long min_num2 = pq.top(); pq.pop();

        long long sum = min_num1 + min_num2;

        pq.push(sum);
        pq.push(sum);
    }

    while(!pq.empty()){
        result += pq.top();
        pq.pop();
    }

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}