#include <iostream>

using namespace std;
#define endl "\n"
#define ll long long

int N;
string S;

int get_index(int t, int g, int f, int p){
    return 27*t + 9*g + 3*f + 1*p;
}

void input(){
    cin >> N;
    cin >> S;
}

void func(){
    ll result = 0;
    int t=0, g=0, f=0, p=0;

    ll cnt[81] = {0};
    cnt[0] = 1;

    for(int i=0; i < N; i++){
        char c = S[i];

        if(c == 'T') t = (t+1)%3;
        else if(c == 'G') g = (g+1)%3;
        else if(c == 'F') f = (f+1)%3;
        else p = (p+1)%3;

        int idx = get_index(t, g, f, p);
        result += cnt[idx];
        cnt[idx]++;
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}