#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> v;

void input(){
    cin >> n;
    v.resize(n+1, vector<int>(6));

    for(int i=1; i <= n; i++){
        for(int j=1; j <= 5; j++){
            cin >> v[i][j];
        }
    }
}

void func(){
    int max = 0, result = 1;
    for(int i=1; i <= n; i++){
        int cnt = 0;
        for(int j=1; j <= n; j++){
            if(i==j) continue;

            for(int k=1; k <= 5; k++){
                if(v[i][k] == v[j][k]){
                    cnt++;
                    break;
                }
            }
        }
        if(cnt > max || (cnt == max && i < result)){
            max = cnt;
            result = i;
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}