#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> m;

void input(){
    cin >> N >> M;
    m.resize(N+1, vector<int>(N+1, 1e9));

    for(int i=0; i < M; i++){
        int v1, v2;
        cin >> v1 >> v2;
        m[v1][v2] = 1;
        m[v2][v1] = 1;
    }
}

void func(){
    int result = -1; 
    int min_total = 1e9;

    for(int k=1; k <= N; k++){
        for(int i=1; i <= N; i++){
            for(int j=1; j <= N; j++){
                if(m[i][k] + m[k][j] < m[i][j]){
                    m[i][j] = m[i][k] + m[k][j];
                }
            }
        }
    }

    for(int i=1; i <= N; i++){
        int total = 0;
        for(int j=1; j <= N; j++){
            total += m[i][j];
        }
        if(total < min_total){
            min_total = total;
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