#include <string>
#include <vector>

using namespace std;
#define MAX 100001

int fib[MAX] = {0};

int get_fib(int n){
    if(n==0) return 0;
    
    if(!fib[n]){
        return fib[n] = (get_fib(n-1) + get_fib(n-2))%1234567;
    }
    else return (fib[n]%1234567);
}

int solution(int n) {
    fib[1] = 1;
    
    return get_fib(n);
}