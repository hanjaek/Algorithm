#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    int N;
    vector<int> stack;
    string line;

    cin >> N;
    cin.ignore();

    for(int i=0; i < N; i++){
        string command;
        int number;
        getline(cin, line);

        istringstream separation(line);
        separation >> command;

        if(command == "push"){
            separation >> number;
            stack.push_back(number);
        }
        else if(command == "pop"){
            if(!stack.empty()){
                cout << stack.back() << "\n";
                stack.pop_back();
            }
            else{
                cout << -1 << "\n";
            }
        }
        else if(command == "size"){
            cout << stack.size() << "\n";
        }
        else if(command == "empty"){
            if(stack.empty()){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(command == "top"){
            if(!stack.empty()){
                cout << stack.back() << "\n";
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