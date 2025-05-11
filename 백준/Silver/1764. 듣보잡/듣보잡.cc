#include <iostream>
#include <map>

using namespace std;

int main(){

    int N, M; // N: 듣도 못한 사람 수, M: 보도 못한 사람 수
    string name;
    map<string, int> m;
    int cnt = 0;

    cin >> N >> M;

    for(int i=0; i < N; i++){
        cin >> name;
        m[name];
    }

    for(int i=0; i < M; i++){
        cin >> name;

        if(m.count(name) > 0){
            m[name]++;
            cnt++;
        }
        else{
            m[name];
        }
    }

    cout << cnt << "\n";

    for(auto element : m){
        if(element.second == 1){
            cout << element.first << "\n";
        }
    }
}