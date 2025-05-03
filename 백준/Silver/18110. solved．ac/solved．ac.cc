#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    if(N==0){
        cout << 0;
        return 0;
    }
    vector<int> v;
    int number;
    int del_num = round(N * 0.15);

    for(int i=0; i < N; i++){
        cin >> number;
        v.push_back(number);
    }

    sort(v.begin(), v.end());

    double score = 0.0;
    int cnt = 0;
    for(int i=del_num; i < v.size()-del_num ; i++){
        score += v[i];
        cnt++;
    }

    cout << (int)round(score / cnt);

}