#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    map<int, int> m;
    vector<int> v(N);
    int sum = 0;
    int max_value = -9999;
    int min_value = 9999;

    for(int i=0; i < N; i++){
        cin >> v[i];
        sum += v[i];
        if(max_value < v[i]){
            max_value = v[i];
        }
        if(min_value > v[i]){
            min_value = v[i];
        }
    }

    for(auto element : v){
        m[element]++;
    }

    int max_cnt = 0;
    for(auto &element : m){
        if(element.second > max_cnt){
            max_cnt = element.second;
        }
    }

    vector<int> modes;
    for(auto &element : m){
        if(element.second == max_cnt){
            modes.push_back(element.first);
        }
    }

    sort(v.begin(), v.end());

    // 산술 평균
    // cout << fixed << setprecision(0) << (double)sum / N << "\n";
    cout << (int)round((double)sum/N) << "\n";
    
    // 중앙값
    cout << v[N/2] << "\n";

    // 최빈값(중복시 2번째로 작은 숫자)
    if(modes.size() > 1){
        cout << modes[1] << "\n";
    }
    else{
        cout << modes[0] << "\n";
    }

    // 최대값 최소값 차이
    cout << abs(max_value - min_value);

}
