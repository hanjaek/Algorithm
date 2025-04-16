#include <iostream>
#include <vector>

using namespace std;

int main(){

    int testcase, floor, room;
    cin >> testcase;

    for(int i=0; i<testcase; i++){

        cin >> floor >> room;
        vector<vector<int>> apt(floor+1, vector<int>(room, 0)); // floor: 층(행), room: 호수(열) 2차원 벡터

        // 0층의 i호는 i명 세팅
        // 층의 인덱스는 그대로 사용하면 되지만, 호수는 1호실부터기 때문에 인덱스값 -1로 생각, 1호는 0번 인덱스
        for(int j=0; j < room; j++){
            apt[0][j] = j+1;
        }

        for(int j=1; j <= floor; j++){
            for(int k=0; k < room; k++){
                int cnt = 0;
                
                for(int l=0; l <= k; l++){
                    cnt += apt[j-1][l];
                }
                apt[j][k] = cnt;
            }
        }

        cout << apt[floor][room-1] << "\n";
    }
}