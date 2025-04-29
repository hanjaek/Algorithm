#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){

    // 시간초과 X

    // int N, M;
    // cin >> N;
    // vector<int> numbers(N);
    // for(int i=0; i < N; i++){
    //     cin >> numbers[i];
    // }

    // cin >> M;
    // vector<int> cnt(M, 0);
    // int number;

    // for(int i=0; i < M; i++){
    //     cin >> number;

    //     for(auto element : numbers){
    //         if(element == number){
    //             cnt[i]++;
    //         }
    //     }
    // }

    // for(auto element : cnt){
    //     cout << element << " ";
    // }

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, number;
    map<int, int> number_cnt;

    cin >> N;
    for(int i=0; i < N; i++){
        cin >> number;
        number_cnt[number]++;
    }

    cin >> M;
    vector<int> numbers(M);
    for(int i=0; i < M; i++){
        cin >> numbers[i];
    }

    for(int i=0; i < M; i++){
        cout << number_cnt[numbers[i]] << " ";
    }
}