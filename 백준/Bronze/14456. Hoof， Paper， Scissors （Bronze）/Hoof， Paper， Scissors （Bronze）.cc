#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl "\n"

int N;
vector<pair<int ,int>> v;

// Hoof, Paper, Scissors - 1, 2, 3
bool win(int a, int b){
    return (a==1 && b==3 || a==2 && b==1 || a==3 && b==2);
}

void input(){
    cin >> N;
    v.resize(N);

    for(int i=0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }
}

void func(){
    int result = 0;
    int cases[3] = {1, 2, 3};

    do{
        int cnt = 0;

        for(pair<int, int> p : v){
            int a = cases[p.first-1];
            int b = cases[p.second-1];

            if(win(a, b)) cnt++;
        }
        result = max(result, cnt);

    }while(next_permutation(cases, cases + 3));

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}