#include <iostream>
#include <algorithm>

using namespace std;
#define endl "\n"

int N;

bool check_right_triangle(int a, int b, int c){
    return ((a*a + b*b == c*c));
}

void input(){
    cin >> N;
}

void func(){
    for(int i=1; i <= N; i++){
        int arr[3];
        cin >> arr[0] >> arr[1] >> arr[2];

        sort(arr, arr+3);

        cout << "Scenario #" << i << ":" << endl;
        cout << (check_right_triangle(arr[0], arr[1], arr[2]) ? "yes" : "no") << endl;
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}