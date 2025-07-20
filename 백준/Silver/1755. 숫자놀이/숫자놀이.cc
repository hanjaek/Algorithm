#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int M, N;
vector<pair<string, int>> words;

string num_to_word(int num){
    string digit[10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };

    if(num < 10) return digit[num];
    return digit[num/10] + " " + digit[num%10];
}

void input(){
    cin >> M >> N;
}

void func(){
    for(int i=M; i <= N; i++){
        words.push_back({num_to_word(i),i});
    }

    sort(words.begin(), words.end());

    for(int i=0; i < words.size(); i++){
        cout << words[i].second << " ";
        if((i+1)%10==0) cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}