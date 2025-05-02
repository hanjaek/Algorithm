#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;
    vector<int> v(K);
    vector<int> result;

    for(int i=0; i < K; i++){
        v[i] = i+1;
    }

    int idx = 0;
    int cnt = 1;

    while(!v.empty()){

        if(cnt == N){
            result.push_back(v[idx]);
            v.erase(v.begin() + idx);
            cnt = 1;
            if(idx >= v.size()) idx = 0;
        }
        else{
            idx++;
            if(idx >= v.size()) idx = 0;
            cnt++;
        }

    }

    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << ">";

}