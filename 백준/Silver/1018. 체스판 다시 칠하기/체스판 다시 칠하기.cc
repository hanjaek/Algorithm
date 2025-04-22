#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 8 

int main(){

    int N, M;
    cin >> N >> M;
    vector<string> chess(N, string(M, ' '));
    int min_change = 64;

    for(int i=0; i < N; i++){
        cin >> chess[i];
    }

    for(int i=0; i <= N - MAX; i++){
        for(int j=0; j <= M - MAX; j++){
            
            int change = 0;
            char start_color = chess[i][j];

            for(int x=0; x < MAX; x++){
                for(int y=0; y < MAX; y++){

                    char expect_color;

                    if((x + y) % 2 == 0){
                        expect_color = start_color;
                    }
                    else{
                        if(start_color == 'W'){
                            expect_color = 'B';
                        }
                        else{
                            expect_color = 'W';
                        }
                    }

                    if(chess[i+x][j+y] != expect_color){
                        change++;
                    }
                }
            }

            int op_change = 64 - change;
            min_change = min(min_change, min(change, op_change));
        }
    }
    cout << min_change ;
}