#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int A, B, C;
int S;
bool visited[1501][1501];

void input(){
    cin >> A >> B >> C;
}

bool bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        int cz = S - cx - cy;
        if(cx == cy && cy == cz) return true;

        int X[3] = {cx, cx, cy};
        int Y[3] = {cy, cz, cz};

        for(int i=0; i < 3; i++){
            int a = X[i];
            int b = Y[i];

            if(a == b) continue;
            if(a > b) swap(a, b);

            int na = a + a;
            int nb = b - a;
            int nc = S - na - nb;

            int arr[3] = {na, nb, nc};
            sort(arr, arr + 3);

            na = arr[0];
            nb = arr[1];

            if(!visited[na][nb]){
                visited[na][nb] = true;
                q.push({na, nb});
            }
        }
    }
    return false;
}

void func(){
    S = A + B + C;

    if(S % 3 != 0){
        cout << 0 << "\n";
        return;
    }

    int t[3] = {A, B, C};
    sort(t, t + 3);
    int a = t[0];
    int b = t[1];

    if(bfs(a, b)){
        cout << 1 << "\n";
    }
    else{
        cout << 0 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}