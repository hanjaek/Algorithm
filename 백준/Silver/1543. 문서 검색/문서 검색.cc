#include <iostream>
#include <string>

using namespace std;

string doc, word;

void input(){
    getline(cin, doc);
    getline(cin, word);
}

void func(){
    int cnt = 0, idx = 0;

    if (doc.length() < word.length()) {
        cout << 0;
        return;
    }

    while(idx <= doc.length() - word.length()){
        if(doc.substr(idx, word.length()) == word){
            cnt++;
            idx += word.length();
        }
        else{
            idx++;
        }
    }
    cout << cnt;
}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}