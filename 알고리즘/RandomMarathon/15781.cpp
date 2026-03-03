#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N, M;
vector<int> helmets;
vector<int> vests;

void input(){
    cin >> N >> M;
    helmets.resize(N);
    vests.resize(M);

    for(int i=0; i < N; i++){
        cin >> helmets[i];
    }
    for(int i=0; i < M; i++){
        cin >> vests[i];
    }
}

void func(){
    int mx_helmet = *max_element(helmets.begin(), helmets.end());
    int mx_vest = *max_element(vests.begin(), vests.end());

    cout << mx_helmet + mx_vest << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}