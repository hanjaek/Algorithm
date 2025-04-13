#include <iostream>

using namespace std;

int main(){

    int testcase;
    cin >> testcase;

    for(int i=0; i < testcase; i++){

        int result = 0;
        string str;
        cin >> str;

        int score = 1;

        for(int i=0; i < str.size(); i++){

            if(str[i]=='O'){
                if((i>0) && (str[i-1] == 'O')){
                    score ++;
                }
                result += score;
            }
            else{
                score = 1;
            }
        }

        cout << result << "\n";
    }
}