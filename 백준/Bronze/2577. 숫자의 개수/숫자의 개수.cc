#include <iostream>
#include <string>

using namespace std;

int main(){

    int a, b, c;
    int cnt_arr[10]={0};
    string number;

    cin >> a;
    cin >> b;
    cin >> c;
    number = to_string(a*b*c);

    for(int i=0; i < number.size(); i++){
        int cnt = number[i] - '0';

        cnt_arr[cnt]++;
    }
    
    for(int j=0; j < 10; j++){
        cout << cnt_arr[j] << "\n";
    }
}