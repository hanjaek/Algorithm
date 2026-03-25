#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N;
vector<int> A;

void input(){
    cin >> N;
    A.resize(N);

    for(int i=0; i < N; i++){
        cin >> A[i];
    }
}

void func(){
    int result = 0;
    sort(A.begin(), A.end());
    
    for(int i=0; i < N; i++){
        int target = A[i];
        int left = 0;
        int right = N - 1;
        
        while(left < right){
            if(left == i){
                left++; continue;
            }
            if(right == i){
                right--; continue;
            }

            int sum = A[left] + A[right];

            if(sum == target){
                result++;
                break;
            }
            if(sum < target) left++;
            else right--;
        }
    }

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}