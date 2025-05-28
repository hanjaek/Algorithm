#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> m;
int white = 0, blue = 0;

bool is_same_color(int x, int y, int size){
    
    int color = m[x][y];
    for(int i=x; i < x+size; i++){
        for(int j=y; j < y+size; j++){
            if(m[i][j]!=color){
                return false;
            }
        }
    }
    return true;

}

void devide(int x, int y, int size){

    if(is_same_color(x, y, size)){
        if(m[x][y]==0){
            white++;
        }
        else{
            blue++;
        }
        return;
    }

    int half = size/2;
    devide(x, y, half);
    devide(x + half, y, half);
    devide(x, y + half, half);
    devide(x + half, y + half, half);

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    m.resize(n, vector<int>(n, 0));

    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> m[i][j];
        }
    }

    devide(0, 0, n);

    cout << white << "\n" << blue;

}