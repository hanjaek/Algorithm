#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int k;
vector<int> numbers;
vector<int> mask;
bool flag = true;

void input(){
    numbers.clear();
    mask.clear();
    numbers.resize(k);
    mask.assign(k, 1);

    for(int i=0; i < k; i++){
        cin >> numbers[i];
    }
}

void func(){
    sort(numbers.begin(), numbers.end());

    for(int i=0; i < 6; i++) mask[i] = 0;

    do{
        for(int i=0; i < k; i++){
            if(mask[i]) continue;
            cout << numbers[i] << " ";
        }
        cout << endl;
    }while(next_permutation(mask.begin(), mask.end()));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1){
        cin >> k;
        if(k==0) break;

        if(!flag) cout << endl;
        flag = false;

        input();
        func();
    }
}