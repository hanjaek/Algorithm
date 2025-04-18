#include <iostream>
#include <string>

using namespace std;

int main(){

    // 적어도 6이 3개이상 연속해야함.
    int N;
    int title = 666;
    string stitle;
    int cnt = 0;

    cin >> N;

    for(title; ; title++){
        stitle = to_string(title);
        
        if(stitle.find("666") != -1){
            cnt++;
            if( cnt == N ){
                cout << title;
                return 0;
            }
        }
    }
}