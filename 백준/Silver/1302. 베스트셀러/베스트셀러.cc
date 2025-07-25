#include <iostream>
#include <map>
#include <string>

using namespace std;

int N;
map<string, int> books;

void input(){
    cin >> N;
    for(int i=0; i < N; i++){
        string title;
        cin >> title;
        books[title]++;
    }
}

void func(){
    string best = "";
    int max = 0;

    for(auto &element : books){
        if(element.second > max){
            max = element.second;
            best = element.first;
        }
    }
    cout << best;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}