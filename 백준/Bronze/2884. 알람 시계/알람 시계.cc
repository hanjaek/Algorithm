#include <iostream>

using namespace std;

int main(){

    // 입력보다 45분 일찍 출력 (h:0~23)(m:0~59)
    unsigned short hour, minute;

    cin >> hour >> minute;

    
    if(minute - 45 < 0){
        minute = 60 + (minute - 45);
        
        if (hour == 0){
            hour = 23;
        }
        else{
            hour--;
        }
    }
    else{
        minute -= 45;
    }

    cout << hour << " " << minute ;
}