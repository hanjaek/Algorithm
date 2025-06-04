#include <iostream>

using namespace std;

int hour, minute, use_time;

void input(){
    cin >> hour >> minute;
    cin >> use_time;
}

void func(){
    minute += use_time;
    hour += minute / 60;
    minute %= 60;
    hour %= 24;
    cout << hour << " " << minute;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}