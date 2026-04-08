#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N, K;
vector<int> A;
vector<bool> on_robot;

bool check_k(){
    int cnt = 0;

    for(int i=0; i < A.size(); i++){
        if(A[i] == 0) cnt++;
    }

    return (cnt >= K);
}

void add_robot(){
    if(A[0] > 0 && !on_robot[0]){
        on_robot[0] = true;
        A[0]--;
    }
}

void delete_robot(){
    int idx = N-1;
    if(on_robot[idx]){
        on_robot[idx] = false;
    }
}

void rotate_belt(vector<int> &v1, vector<bool> &v2){
    rotate(v1.begin(), v1.end()-1, v1.end());
    rotate(v2.begin(), v2.end()-1, v2.end());
    delete_robot();
}

void move_robot(){
    int mid = N/2 - 1;

    for(int i=N-1; i >= 0; i--){
        int next_idx = i+1;

        if(on_robot[i] && !on_robot[next_idx] && A[next_idx] > 0){
            on_robot[next_idx] = true;
            A[next_idx]--;
            on_robot[i] = false;
        }
    }
    delete_robot();
}

void input(){
    cin >> N >> K;
    A.resize(2*N);
    on_robot.resize(N, false);

    for(int i=0; i < 2*N; i++){
        cin >> A[i];
    }
}

void func(){
    int result = 0;

    while(true){
        result++;
        rotate_belt(A, on_robot);
        move_robot();
        add_robot();
        if(check_k()) break;
    }

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}