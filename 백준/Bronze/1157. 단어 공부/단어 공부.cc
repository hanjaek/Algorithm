#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;
#define endl "\n"

string str;
int cnt[26] = {0};

void input(){
    cin >> str;
}

void func(){
    int mx = 0;
    char result = '?';

    for(char c : str){
        c = toupper(c);
        cnt[c-'A']++;
    }

    for(int i=0; i < 26; i++){
        if(cnt[i] > mx){
            mx = cnt[i];
            result = i + 'A';
        }
        else if(cnt[i] == mx){
            result = '?';
        }
    }

    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    input();
    func();
}