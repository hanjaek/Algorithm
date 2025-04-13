#include <iostream>
#include <string>

using namespace std;

int main(){

    unsigned short testcase;

    cin >> testcase;

    for(int i=0; i < testcase; i++){

        int repeat;
        string str;
        string re_str;

        cin >> repeat >> str;

        // 처음에 repeat만큼 했다가 틀림 -> 이유) 문자열이 1개로 가정하면 str[j]에서 범위를 벗어남.
        for(int j=0; j < str.size(); j++){
            re_str.append(repeat, str[j]);
        }

        cout << re_str << "\n";

    }
}