#include <iostream>
#include <cmath>

using namespace std;

int D, W, H; // 비율 - 대각, 높이, 너비
// x = kW, y = kH  k:ratio 
// D2 = x2 + y2 = (kW)2 + (kH)2 -> k = D/sqrt(W2+H2)
// x = WD/sqrt(W2+H2), y = HD/sqrt(W2+H2)

void input(){
    cin >> D >> W >> H;
}

void func(){
    double ratio = sqrt(H*H + W*W);
    int width = (int)(W*D/ratio);
    int height = (int)(H*D/ratio);

    cout << width << " " << height;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}