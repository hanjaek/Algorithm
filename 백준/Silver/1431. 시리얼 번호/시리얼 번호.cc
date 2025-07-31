#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int N;
vector<string> serials;

void input(){
    cin >> N;
    serials.resize(N);
    for(int i=0; i < N; i++){
        cin >> serials[i];
    }
}

int get_sum(string &s){
    int sum = 0;
    for(char c : s){
        if(isdigit(c)){
            sum += c - '0';
        }
    }
    return sum;
}

bool cmp(string &s1, string &s2){
    if(s1.length() != s2.length()){
        return s1.length() < s2.length();
    }

    int sum_s1 = get_sum(s1);
    int sum_s2 = get_sum(s2);
    if(sum_s1 != sum_s2){
        return sum_s1 < sum_s2;
    }
    return s1 < s2;
}

void func(){
    sort(serials.begin(), serials.end(), cmp);

    for(string &s : serials){
        cout << s << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}