#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nine(9);
vector<int> seven(7);

void input(){
    for(int i=0; i < 9; i++){
        cin >> nine[i];
    }
}

void func(){
    int sum = 0;
    int no1 = -1, no2 = -1;
    int idx = 0;

    for(int element : nine){
        sum += element;
    }


    for(int i=0; i < 9; i++){
        for(int j=i+1; j < 9; j++){
            if(sum - nine[i] - nine[j] == 100){
                no1 = i; no2 = j;
                break;
            }
        }
        if(no1 != -1) break;
    }

    for(int i=0; i < 9; i++){
        if(i == no1 || i == no2) continue;
        seven[idx++] = nine[i];
    }

    sort(seven.begin(), seven.end());
    for(int element : seven){
        cout << element << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}