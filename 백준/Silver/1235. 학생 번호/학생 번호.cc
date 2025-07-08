#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int N;
vector<string> numbers;

void input(){
    cin >> N;
    numbers.resize(N);
    for(int i=0; i < N; i++){
        cin >> numbers[i];
    }
}

void func(){
    int len = numbers[0].length();

    for(int k=1; k <= len; k++){
        set<string> result;
        for(int i=0; i < N; i++){
            string number = numbers[i].substr(len-k, k);
            result.insert(number);
        }
        if(result.size() == N){
            cout << k;
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}