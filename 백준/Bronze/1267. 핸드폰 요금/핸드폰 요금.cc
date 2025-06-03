#include <iostream>

using namespace std;

int num, time;
int fee1 = 0, fee2 = 0;

void input(){
    cin >> num;
    for(int i=0; i < num; i++){
        cin >> time;
        fee1 += (time / 30 + 1) * 10;
        fee2 += (time / 60 + 1) * 15;
    }
}

void func(){
    if(fee1 < fee2){
        cout << "Y " << fee1;
    }
    else if(fee1 == fee2){
        cout << "Y M " << fee1;
    }
    else{
        cout << "M " << fee2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}