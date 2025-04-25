#include <iostream>
#include <vector>

using namespace std;

int main(){

    // ######## Greedy

    // int N;
    // int cnt = 0;

    // cin >> N;

    // while(N >= 0){
    //     if(N % 5 == 0){
    //         cnt += N / 5;
    //         cout << cnt;
    //         return 0;
    //     }
    //     else{
    //         N -= 3;
    //         cnt ++;
    //     }
    // }

    // cout << -1;

    // ######### DP

    int N;
    cin >> N;
    vector<int> sugar(N + 1, -1);
    sugar[0] = 0;

    for(int kg=1; kg <= N; kg++){

        if(kg >= 3 && sugar[kg-3] != -1){
            sugar[kg] = sugar[kg-3] + 1;
        }

        if(kg >= 5 && sugar[kg-5] != -1){
            if(sugar[kg] == -1){
                sugar[kg] = sugar[kg-5] + 1;
            }
            else{
                sugar[kg] = min(sugar[kg], sugar[kg-5] + 1);
            }
        }
    }

    // for(auto element : sugar){
    //     cout << element << " ";
    // }

    cout << sugar[N];

}