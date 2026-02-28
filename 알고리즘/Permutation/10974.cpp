#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N;
vector<int> numbers;

void input(){
    cin >> N;
}

void func(){
    numbers.clear();

    for(int i=1; i <= N; i++){
        numbers.push_back(i);
    }

    // do{
    //     for(int num : numbers) cout << num << " ";
    //     cout << endl;
    // }while(next_permutation(numbers.begin(), numbers.end()));

    do{
        for(auto it = numbers.begin(); it != numbers.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }while(next_permutation(numbers.begin(), numbers.end()));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
    return 0;
}