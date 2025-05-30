#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> tree(n);
    for(int i=0; i < n; i++){
        cin >> tree[i];
    }

    int left = 0;
    int right = *max_element(tree.begin(), tree.end());
    int result = 0;

    while(left <= right){

        long long sum = 0;
        int mid = (left + right) / 2;

        for(auto cut : tree){
            if(cut > mid){
                sum += (cut - mid);
            }
        }

        if(sum >= m){
            result = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    cout << result;
    
}