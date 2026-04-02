#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    
    for(int i=3; i < total; i++){
        for(int j=3; j <= i; j++){
            if(i*j == total){
                if((i-2)*(j-2) == yellow){
                    return {i, j};
                }
            }
        }
    }
}