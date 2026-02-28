#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N;
vector<vector<int>> scores;
vector<int> mask;

void input(){
    cin >> N;
    scores.resize(N, vector<int>(N, 0));
    mask.resize(N, 0);

    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            cin >> scores[i][j];
        }
    }
}

void func(){
    int result = 1e9;

    for(int i=N/2; i < N; i++){
        mask[i] = 1;
    }

    do{
        int team_start = 0;
        int team_link = 0;

        for(int i=0; i < N; i++){
            for(int j=i+1; j < N; j++){
                if(mask[i] == 0 && mask[j] == 0){
                    team_start += (scores[i][j] + scores[j][i]);
                }
                else if(mask[i] == 1 && mask[j] == 1){
                    team_link += (scores[i][j] + scores[j][i]);
                }
            }
        }
        result = min(result, abs(team_start - team_link));
    }while(next_permutation(mask.begin(), mask.end()));

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();

    return 0;
}