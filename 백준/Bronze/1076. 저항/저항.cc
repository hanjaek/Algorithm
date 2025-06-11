#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

map <string, int> resist = {
    {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3},
    {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7},
    {"grey", 8}, {"white", 9}
};
string color1, color2, color3;

void input(){
    cin >> color1 >> color2 >> color3;
}

void func(){
    long long result = (resist[color1] * 10 + resist[color2]) * (long long)pow(10, resist[color3]);
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}