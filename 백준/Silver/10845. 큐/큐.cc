#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main(){

    queue<int> q;
    int N;
    string line;

    cin >> N;
    cin.ignore();

    for(int i=0; i < N; i++){
        getline(cin, line);
        string command;
        int number;
        istringstream ss(line);

        ss >> command;

        if(command == "push"){
            ss >> number;
            q.push(number);
        }
        else if(command == "pop"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(command == "size"){
            cout << q.size() << "\n";
        }
        else if(command == "empty"){
            if(!q.empty()){
                cout << 0 << "\n";
            }
            else{
                cout << 1 << "\n";
            }
        }
        else if(command == "front"){
            if(!q.empty()){
                cout << q.front() << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(command == "back"){
            if(!q.empty()){
                cout << q.back() << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
        else{
            cout << "not command" << "\n";
        }
    }

}