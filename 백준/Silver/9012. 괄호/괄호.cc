#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    vector<char> stack;
    cin >> N;
    cin.ignore();

    for(int i=0; i < N; i++){

        string line;
        getline(cin, line);
        bool vps = true;

        for(char element : line){

            if(element == '('){
                stack.push_back(element);
            }
            else{
                if(!stack.empty() && stack.back() == '('){
                    stack.pop_back();
                }
                else{
                    vps = false;
                    break;
                }
            }
        }

        if(vps && stack.empty()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }

        stack.clear();
    }

}