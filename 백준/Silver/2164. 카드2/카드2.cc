#include <iostream>
#include <queue>

using namespace std;

int main(){

    int N;
    queue<int> q;

    cin >> N;
    for(int i=1; i <= N; i++){
        q.push(i);
    }

    int number; 

    while(q.size() != 1){

        q.pop();
        number = q.front();
        q.pop();
        q.push(number);

    }

    cout << q.front();

}