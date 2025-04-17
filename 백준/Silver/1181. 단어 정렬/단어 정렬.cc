#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(string &str1, string &str2){

    string temp = str1;
    str1 = str2;
    str2 = temp;

}

int partition(vector<string> &alpha, int l, int r){

    int left = l;
    int right = r;
    string pivot = alpha[(left + right)/2];

    while(left <= right){
        
        while(alpha[left].size() < pivot.size() || ((alpha[left].size() == pivot.size()) && ( alpha[left] < pivot))){
            left++;
        }

        while(alpha[right].size() > pivot.size() || ((alpha[right].size() == pivot.size()) && ( alpha[right] > pivot))){
            right--;
        }

        if(left <= right){
            if(alpha[left].size() == alpha[right].size()){
                if(alpha[left] > alpha[right]){
                    swap(alpha[left], alpha[right]);
                }
            }
            else{
                swap(alpha[left], alpha[right]);
            }
            left++;
            right--;
        }
    }

    return left;
}

void quick_sort(vector<string> &alpha, int left, int right){

    if(left >= right) return;

    int pivot = partition(alpha, left, right);
    quick_sort(alpha, left, pivot-1);
    quick_sort(alpha, pivot, right);

}

int main(){

    int N;
    vector<string> alpha;
    string str;

    cin >> N;

    for(int i=0; i < N; i++){
        cin >> str;
        alpha.push_back(str);
    }

    quick_sort(alpha, 0, alpha.size()-1);
  
    alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());

    for(string element : alpha){
        cout << element << "\n";
    }
}