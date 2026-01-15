#include <iostream>
#include <vector>

#define endl "\n"
#define MAX 101
using namespace std;

int N, x, y, d, g;
int ex, ey;
bool grid[MAX][MAX];
vector<int> vertex;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void make_dragon_curve(){
    int S = vertex.size();
    for(int i = S-1; i >= 0; i--){
        int nd = (vertex[i] + 1) % 4;

        ex += dx[nd];
        ey += dy[nd];
        grid[ex][ey] = true;
        vertex.push_back(nd);
    }
}

void count_square(){
    int cnt = 0;
    
    for(int x=0; x < MAX-1; x++){
        for(int y=0; y < MAX-1; y++){
            if(grid[x][y] && grid[x+1][y] && grid[x][y+1] && grid[x+1][y+1]) cnt++;
        }
    }
    cout << cnt << endl;
}

void input(){
    cin >> N;
}

void func(){
    for(int i=0; i < N; i++){
        vertex.clear();
        cin >> x >> y >> d >> g;

        grid[x][y] = true;
        ex = x + dx[d];
        ey = y + dy[d];
        grid[ex][ey] = true;

        vertex.push_back(d);

        for(int j=0; j < g; j++){
            make_dragon_curve();
        }
    }
    count_square();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}