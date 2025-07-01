#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str;

void input(){
    cin >> str;
}

void func(){
    string result = "z";

    for(int i=1; i < str.length()-1; i++){
        for(int j=i+1; j < str.length(); j++){
            string front = str.substr(0,i);
            string center = str.substr(i, j-i);
            string back = str.substr(j);

            reverse(front.begin(), front.end());
            reverse(center.begin(), center.end());
            reverse(back.begin(), back.end());

            string combine = front + center + back;
            if(combine < result){
                result = combine;
            }
        }
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    func();
}