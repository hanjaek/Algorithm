#include <iostream>
#include <map>
#include <string>

using namespace std;

bool is_number(string &str){

    for(auto element : str){
        if(!isdigit(element)){
            return false;
        }
    }
    return true;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 시간초과했음 -> 그럼 map을 2개 사용

    // int N, M; // N: 도감 수, M: 질문 수
    // map<int, string> poketmon;
    // string search;

    // cin >> N >> M;

    // for(int i=0; i < N; i++){
    //     cin >> poketmon[i];
    // }

    // for(int i=0; i < M; i++){
    //     cin >> search;

    //     if(is_number(search)){
    //         int idx = stoi(search) - 1;
    //         cout << poketmon[idx] << "\n";
    //     }
    //     else{
    //         for(auto element : poketmon){
    //             if(element.second == search){
    //                 cout << element.first + 1 << "\n";
    //             }
    //         }
    //     }
    // }

    int N, M; // N: 도감 수, M: 질문 수
    map<int, string> poketmon_name;
    map<string, int> poketmon_idx;
    string name, search;

    cin >> N >> M;

    for(int i=1; i <= N; i++){
        cin >> name;
        poketmon_name[i] = name;
        poketmon_idx[name] = i;
    }

    for(int i=0; i < M; i++){
        cin >> search;

        if(is_number(search)){
            int idx = stoi(search);
            cout << poketmon_name[idx] << "\n";
        }
        else{
            cout << poketmon_idx[search] << "\n";
        }
    }
    
}