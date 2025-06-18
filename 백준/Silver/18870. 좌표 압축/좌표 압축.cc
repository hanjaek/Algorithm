#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> sorted;
map<int, int> compressed;
int N;

void input(){
    cin >> N;
    arr.resize(N);
    for(int i=0; i < N; i++){
        cin >> arr[i];
    }
}

void func(){
    sorted = arr;
    sort(sorted.begin(), sorted.end());

    int idx = 0;
    for(int i=0; i < N; i++){
        if(compressed.count(sorted[i])==0){
            compressed[sorted[i]] = idx;
            idx++;
        }
    }

    for(int i=0; i < N; i++){
        cout << compressed[arr[i]] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}