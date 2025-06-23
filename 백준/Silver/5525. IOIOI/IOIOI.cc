#include <iostream>

using namespace std;

int N, M;
string s;

void input(){
    cin >> N >> M >> s;
}

void func(){
    int result = 0, cnt = 0;
    int idx = 0;

    while(idx <= M-2){
        if(s[idx] == 'I'){ //패턴 시작
            cnt = 0;
            while(idx + 2 < M && s[idx+1] == 'O' && s[idx+2] == 'I'){
                cnt++;
                idx += 2;
                if(cnt == N){
                    result++;
                    cnt--; // ex) IOIOIOI경우 N=2일 때 2임, 즉 중복제거
                }

            }
        }
        idx++;
    }
    
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}