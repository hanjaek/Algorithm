#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define endl "\n"

string S;

void input(){
    cin >> S;
}

void func(){
    vector<string> result;
    for(int i=0; i < S.size(); i++){
        result.push_back(S.substr(i));
    }
    sort(result.begin(), result.end());

    for(string str : result){
        cout << str << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}