#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    // 나이는 200살까지
    vector<string> person[201];

    cin>> N;
    for(int i=0; i < N; i++){
        int age;
        string name;

        cin >> age >> name;
        person[age].push_back(name);
    }

    for(int age=1; age <= 200; age++){
        for(string element : person[age]){
            cout << age << " " << element << "\n";
        }
    }

}