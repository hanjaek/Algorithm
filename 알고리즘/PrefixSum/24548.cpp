#include <iostream>
#include <map>
#include <tuple>

using namespace std;
#define endl "\n"
#define ll long long

int N;
string S;

void input(){
    cin >> N;
    cin >> S;
}

void func(){
    ll result = 0;
    int t=0, g=0, f=0, p=0;

    map<tuple<int, int, int, int>, ll> cnt;
    cnt[{t, g, f, p}] = 1;

    for(int i=0; i < N; i++){
        char c = S[i];

        if(c == 'T') t = (t+1)%3;
        else if(c == 'G') g = (g+1)%3;
        else if(c == 'F') f = (f+1)%3;
        else p = (p+1)%3;

        result += cnt[{t, g, f, p}];
        cnt[{t, g, f, p}]++;
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}