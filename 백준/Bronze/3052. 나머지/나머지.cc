#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define B 42

int main(){

    int A[10];
    vector<int> v;
    int cnt = 0;

    for(int i=0; i < 10; i++){
        cin >> A[i];
    }

    for(int i=0; i < 10; i++){

        int remain = A[i] % B;

        if(find(v.begin(), v.end(), remain) == v.end()){
            cnt ++;
        }

        v.push_back(remain);
    }

    cout << cnt;
}