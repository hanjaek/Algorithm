#include <iostream>
using namespace std;

int solution(int n)
{
    int power = 0;
    
    while(n > 0){
        if(n % 2 == 0){
            n /= 2;
        }
        else{
            n--;
            power++;
        }
    }
    
    return power;
}