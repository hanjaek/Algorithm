#include <iostream>

using namespace std;

#define NUM 10007

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int tile[1001]={0};

    tile[1] = 1 % NUM;
    tile[2] = 3 % NUM;
    tile[3] = 5 % NUM;  

    cin >> n;

    for(int i=4; i <= n; i++){
        tile[i] = (2*tile[i-2] + tile[i-1]) % NUM;
    }

    cout << tile[n];

}