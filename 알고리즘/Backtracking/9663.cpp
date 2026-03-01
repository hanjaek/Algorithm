#include <iostream>
#include <vector>

using namespace std;
#define endl "\n"

int N;
vector<bool> row, diag1, diag2;
int result = 0;

void dfs(int x){
    if(x==N){
        result++;
        return;
    }

    for(int y=0; y < N; y++){
        if(!row[y] && !diag1[x+y] && !diag2[(y-x)+(N-1)]){
            row[y] = true;
            diag1[x+y] = true;
            diag2[(y-x)+(N-1)] = true;

            dfs(x+1);

            row[y] = false;
            diag1[x+y] = false;
            diag2[(y-x)+(N-1)] = false;
        }
    }
}

void input(){
    cin >> N;
    row.resize(N, false);
    diag1.resize(2*N, false);
    diag2.resize(2*N, false);
}

void func(){
    dfs(0);
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}