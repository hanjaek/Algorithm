#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define endl "\n"

int N;
vector<int> tops;

void input(){
    cin >> N;
    tops.resize(N);

    for(int i=0; i < N; i++){
        cin >> tops[i];
    }
}

// 시간 초과 -> 자료 구조 사용할 것
// void func(){
//     vector<int> answer(N, 0);

//     for(int i=N-1; i > 0; i--){
//         int target = i-1;

//         while(tops[i] > tops[target]){
//             target--;
//             if(target < 0) break;
//         }
//         if(target >= 0) answer[i] = target + 1;
//     }

//     for(int i=0; i < N; i++){
//         cout << answer[i] << " ";
//     }
//     cout << endl;
// }

void func(){
    vector<int> answer(N, 0);
    stack<int> st;
    st.push(0);

    for(int i=1; i < N; i++){
        while(!st.empty() && tops[st.top()] < tops[i]){
            st.pop();
        }
        if(!st.empty()) answer[i] = st.top() + 1;
        st.push(i);
    }

        for(int i=0; i < N; i++){
        cout << answer[i] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}