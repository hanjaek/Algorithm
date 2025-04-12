#include <iostream>

using namespace std;

int main(){

    // t = 테스트 수, h = 호텔 층 수, w = 층의 방 수, n번째 손님
    // 출력 => n번째 손님 방

    unsigned short t, h, w, n;

    cin >> t;
    cin.ignore();

    for(int i=0; i < t; i++){
        cin >> h >> w >> n;

        unsigned short floor, number;
        unsigned short room; 

        if(n % h == 0){
            floor = h;
            number = n / h;
        }
        else{
            floor = n % h;
            number = n / h + 1; // 앞 호수엔 사람 존재
        }

        room = floor * 100 + number;

        cout << room << "\n";
    }

}