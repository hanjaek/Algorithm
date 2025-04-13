#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int alpha[26]; // a-z
    fill(alpha, alpha + 26, -1);

    string str;
    cin >> str;

    for(int i=0; i < str.size(); i++){
        
        if(alpha[str[i]-'a'] == -1){
            alpha[str[i]-'a'] = i;
        }
    }

    for(int i=0; i < 26; i++){
        cout << alpha[i] << " ";
    }
    
}