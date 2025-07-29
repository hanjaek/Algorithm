#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<bool> removed;

void input(){
    cin >> N >> K;
    removed.assign(N+1, false);
}

void func(){
    int cnt = 0;

    for(int i=2; i <= N; i++){
        if(removed[i]) continue;

        for(int j=i; j <= N; j += i){
            if(!removed[j]){
                removed[j] = true;
                cnt++;

                if(cnt == K){
                    cout << j << "\n";
                    return;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}