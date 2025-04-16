#include <iostream>

using namespace std;

int euclid(int a, int b){

    if(b==0){
        return a;
    }
    else{
        return euclid(b, a % b);
    }
}

int main(){

    int n, m ,gcd, lcm;

    cin >> n >> m;

    gcd = euclid(n, m);
    lcm = (n*m) / gcd;

    cout << gcd << "\n" << lcm;

}