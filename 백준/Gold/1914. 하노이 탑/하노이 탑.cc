#include <iostream>
#include <cmath>

using namespace std;
#define endl "\n"

int N;

void hannoi(int N, int from, int by, int to){
    if(N==1){
        cout << from << " " << to << endl;
        return;
    }
    else{
        hannoi(N-1, from, to, by);
        cout << from << " " << to << endl;
        hannoi(N-1, by, from ,to);
    }
}

string get_num(int n){
    string num = "1";

    for(int i=0; i < n; i++){
        int carry = 0;

        for(int j=num.size()-1; j >= 0; j--){
            int cur = (num[j] - '0') * 2 + carry;
            num[j] = (cur % 10) + '0';
            carry = cur / 10;
        }

        if(carry > 0){
            num = char(carry + '0') + num;
        }
    }

    int idx = num.size() - 1;
    while(idx >= 0){
        if(num[idx] > '0'){
            num[idx]--;
            break;
        }
        else{
            num[idx] = '9';
            idx--;
        }
    }
    return num;
}

void input(){
    cin >> N;
}

void func(){
    cout << get_num(N) << endl;

    if(N <= 20){
        hannoi(N, 1, 2, 3);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}