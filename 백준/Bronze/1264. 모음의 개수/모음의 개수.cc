#include <iostream>
#include <string>

using namespace std;

string line;

void input(){
    getline(cin, line);
}

void func(){
    while(true){
        input();
        if(line == "#") break;
        int cnt = 0;
        
        for(char c : line){
            c = tolower(c);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    func();
}
