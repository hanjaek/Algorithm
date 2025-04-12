#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    vector<int> v;

    cin >> n;
    cin.ignore();

    for(int i=0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    int number, max = v[0], min = v[0];

    for(int number : v){
        if(number > max){
            max = number;
        }
        if(number < min){
            min = number;
        }
    }
    
    cout << min << " " << max;
    
}