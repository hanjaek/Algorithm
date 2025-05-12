#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

    int N;
    string line;
    int total_wait_time = 0;

    cin >> N;
    cin.ignore();
    getline(cin, line);

    vector<int> work_time(N);
    vector<int> wait_time(N);
    stringstream ss(line);

    for(int i=0; i < N; i++){
        ss >> work_time[i];
    }

    sort(work_time.begin(), work_time.end());

    wait_time[0] = work_time[0];
    for(int i=1; i < N; i++){
        wait_time[i] = wait_time[i-1] + work_time[i];
    }

    for(auto element : wait_time){
        total_wait_time += element;
    }

    cout << total_wait_time;

}