#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){

    int N;
    cin >> N;
    vector<pair<int, int>> vertex(N);

    for(int i=0; i < N; i++){
        cin >> vertex[i].first >> vertex[i].second;
    }

    sort(vertex.begin(), vertex.end(), compare);

    for(auto element : vertex){
        cout << element.first << " " << element.second << "\n";
    }

}