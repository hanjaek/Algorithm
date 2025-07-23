#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;

void input(){
    cin >> N >> M;
    numbers.resize(N);
    for(int i=0; i < N; i++){
        cin >> numbers[i];
    }
}

void func(){
    sort(numbers.begin(), numbers.end());

    int left = 0, right = N - 1;
    int cnt = 0;

    while(left < right){
        int sum = numbers[left] + numbers[right];
        
        if(sum == M){
            cnt++;
            left++; right--;
        }
        else if(sum < M){
            left++;
        }
        else{
            right--;
        }
    }

    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}