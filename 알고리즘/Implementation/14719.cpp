#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
vector<int> h;

void input(){
    cin >> H >> W;
    h.resize(W);
    for(int i=0; i < W; i++){
        cin >> h[i];
    }
}

void func(){
    int result = 0;
    int l = 0, r = W - 1;
    int l_max = 0, r_max = 0;

    while(l < r){
        if(h[l] < h[r]){
            l_max = max(l_max, h[l]);
            result += l_max - h[l];
            l++;
        }
        else{
            r_max = max(r_max, h[r]);
            result += r_max - h[r];
            r--;
        }
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}