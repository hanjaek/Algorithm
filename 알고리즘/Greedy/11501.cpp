#include <iostream>
#include <vector>

using namespace std;

int T, N;
vector<int> stock;

void input(){
    cin >> N;
    stock.resize(N);

    for(int i=0; i < N; i++){
        cin >> stock[i];
    }
}

void func(){
    long long result = 0;
    int max_price = 0;

    for(int day = N-1; day >= 0; day--){
        if(stock[day] > max_price){
            max_price = stock[day];
        }
        else{
            result += max_price - stock[day];
        }
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        input();
        func();
    }
}