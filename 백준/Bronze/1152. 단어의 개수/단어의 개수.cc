#include <iostream>
#include <sstream>

using namespace std;

int main(){

    string line;
    getline(cin, line);
    stringstream words(line);

    string word;
    int cnt = 0;
    while(words >> word){
        cnt ++;
    }

    cout << cnt;
    
}