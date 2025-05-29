#include <iostream>
#include <algorithm>

using namespace std;

int x, y, w, h, result;

void input(){
    cin >> x >> y >> w >> h;
}

void func(){
    result = min({x, y, w-x, h-y});
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    func();
}