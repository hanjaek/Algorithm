#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int min_pkg = 1000, min_pic = 1000;

void input(){
    cin >> N >> M;
    for(int i=0; i < M; i++){
        int pkg, pic;
        cin >> pkg >> pic;
        min_pkg = min(min_pkg, pkg);
        min_pic = min(min_pic, pic);
    }
}

void func(){
    int cost1 = ((N/6)+1) * min_pkg;
    int cost2 = ((N/6) * min_pkg) + ((N%6) * min_pic);
    int cost3 = N * min_pic;

    cout << min({cost1, cost2, cost3});
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}