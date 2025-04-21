#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> vertex1, pair<int, int> vertex2){
    if(vertex1.second == vertex2.second){
        return vertex1.first < vertex2.first;
    }
    return vertex1.second < vertex2.second;
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