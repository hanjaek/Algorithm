#include <iostream>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int min_mul[50001] = {0};

    cin >> n;

    for(int i=1; i <= n; i++){
        min_mul[i] = i;

        for(int j=1; j*j <= i; j++){
            min_mul[i] = min(min_mul[i], min_mul[i - j*j] + 1);
        }
    }

    cout << min_mul[n];

}