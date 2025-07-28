#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> trees;

int gcd(int a, int b){
    while(b!=0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

void input(){
    cin >> N;
    trees.resize(N);
    for(int i=0; i < N; i++){
        cin >> trees[i];
    }
}

void func(){
    vector<int> diff;
    int result;

    for(int i=1; i < N; i++){
        diff.push_back(trees[i] - trees[i-1]);
    }

    int gc = diff[0];
    for(int i=1; i < diff.size(); i++){
        gc = gcd(gc, diff[i]);
    }

    result = (trees[N-1] - trees[0]) / gc - (N-1);
    cout << result;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}