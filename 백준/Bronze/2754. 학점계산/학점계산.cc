#include <iostream>
#include <map>

using namespace std;

/**
A+: 4.3, A0: 4.0, A-: 3.7

B+: 3.3, B0: 3.0, B-: 2.7

C+: 2.3, C0: 2.0, C-: 1.7

D+: 1.3, D0: 1.0, D-: 0.7

F: 0.0 
**/

int main(){

    map<string,float> score;
    string grade;

    // F -> 0 으로 출력을 0.0으로 하기 위함
    cout.precision(1);
    cout << fixed;

    score["A+"] = 4.3; score["A0"] = 4.0; score["A-"] = 3.7;
    score["B+"] = 3.3; score["B0"] = 3.0; score["B-"] = 2.7;
    score["C+"] = 2.3; score["C0"] = 2.0; score["C-"] = 1.7;
    score["D+"] = 1.3; score["D0"] = 1.0; score["D-"] = 0.7;
    score["F"] = 0.0;

    cin >> grade;
    cout << score[grade];
}

