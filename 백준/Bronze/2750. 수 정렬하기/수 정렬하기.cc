#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int repeat;
vector<int> v;

void input(){
    cin >> repeat;
    v.resize(repeat);

    for(int i=0; i < repeat; i++){
        cin >> v[i];
    }
}

void func(){
    sort(v.begin(), v.end());
    
    for(auto element : v){
        cout << element << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}