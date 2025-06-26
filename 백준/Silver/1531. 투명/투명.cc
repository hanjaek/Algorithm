#include <iostream>

using namespace std;

int paper[101][101];
int N, M;

void input(){
    cin >> N >> M;
    for(int i=0; i < N; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int x = x1; x <= x2; x++){
            for(int y = y1; y <= y2; y++){
                paper[x][y]++;
            }
        }
    }
}

void func(){
    int result = 0;
    for(int x=1; x <= 100; x++){
        for(int y=1; y <= 100; y++){
            if(paper[x][y] > M) result++;
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