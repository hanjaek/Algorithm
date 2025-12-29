#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> line;

void input(){
    cin >> N;
    v.resize(N+1);
    line.clear();

    for(int i=1; i <= N; i++){
        cin >> v[i];
    }
}

void func(){
    for(int i = N; i >= 1; i--){
        line.insert(line.begin() + v[i], i);
    }

    for(int i = 0; i < N; i++){
        cout << line[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}