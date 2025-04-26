#include <iostream>
#include <vector>

using namespace std;

int main(){

    while(1){

        vector<char> stack;
        string line;
        bool balance = true;

        getline(cin, line);
        if(line == ".") {
            return 0;
        }

        for(char element : line){

            if(element == '(' || element == '['){
                stack.push_back(element);
            }
            else if(element == ']'){
                if(!stack.empty() && stack.back() == '['){
                    stack.pop_back();
                }
                else{
                    balance = false;
                    break;
                }
            }
            else if(element == ')'){
                if(!stack.empty() && stack.back() == '('){
                    stack.pop_back();
                }
                else{
                    balance = false;
                    break;
                }
            }

        }

        if(balance && stack.empty()){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }

    }

}