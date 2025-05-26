#include <iostream>

using namespace std;

int main(){

    // 최소값 만들기 -> -를 뒤를 기준으로 괄호를 하면 결과값이 작아짐
    // Think : 첫 - 기호만 파싱하면 그 뒤부터는 -든 +든 전부다 빼버리면 됨 -> 최소값 어차피 묶으면 그만이니까

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    bool minus_flag = false;
    string num = "";
    int result = 0;

    cin >> str;

    for(int i=0; i < str.size(); i++){
        
        char c = str[i];
        if(c == '+' || c == '-'){
            int n = stoi(num);
            if(minus_flag){
                result -= n;
            }
            else{
                result += n;
            }
            num = "";
        }
        else{
            num += c;
        }

        if(c == '-'){
            minus_flag = true;
        }
    }

    if(!num.empty()){
        int n = stoi(num);
        if(minus_flag){
            result -= n;
        }
        else{
            result += n;
        }
    }
    cout << result;

}