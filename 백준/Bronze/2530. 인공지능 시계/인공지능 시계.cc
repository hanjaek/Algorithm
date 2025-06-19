#include <iostream>

using namespace std;

int A, B, C, D;

void input(){
    cin >> A >> B >> C;
    cin >> D;
}

void func(){
    int total = A * 3600 + B * 60 + C + D;

    int hour = (total / 3600) % 24;
    int minute = (total % 3600) / 60;
    int second = (total % 60);

    cout << hour << " " << minute << " " << second << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}