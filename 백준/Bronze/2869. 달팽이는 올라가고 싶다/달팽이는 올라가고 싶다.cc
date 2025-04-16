#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){

    // 반복문 사용했을 때, 시간초과했음.
    int A, B ,V;
    double day;

    cin >> A >> B >> V;

    day = ceil(double(V-B) / double(A-B));

    // le+ 형태로 표시되는 것을 막기위해 setprecision을 사용해야함
    cout << fixed << setprecision(0) << day;

}