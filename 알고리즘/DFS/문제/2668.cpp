#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> numbers;
vector<bool> visited;
vector<bool> finished;
vector<int> result;

void input(){
    cin >> N;
    numbers.resize(N+1);
    visited.resize(N+1, false);
    finished.resize(N+1, false);

    for(int i=1; i <= N; i++){
        cin >> numbers[i];
    }
}

void dfs(int start){
    visited[start] = true;
    int next = numbers[start];

    if(!visited[next]){
        dfs(next);
    }
    else if(!finished[next]){
        for(int i=next; i != start; i=numbers[i]){
            result.push_back(i);
        }
        result.push_back(start);
    }
    finished[start] = true;
}

void func(){
    for(int i=1; i <= N; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for(int element : result){
        cout << element << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}