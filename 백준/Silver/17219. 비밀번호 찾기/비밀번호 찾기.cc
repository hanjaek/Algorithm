#include <iostream>
#include <map>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, M; // N: 저장된 사이트 비밀번호 수, M: 찾으려는 사이트 비밀번호 수
    map<string, string> m;
    string site, pwd;

    cin >> N >> M;

    for(int i=0; i < N; i++){
        cin >> site >> pwd;
        m[site] = pwd;
    }

    for(int i=0; i < M; i++){
        cin >> site;
        cout << m[site] << "\n";
    }
}