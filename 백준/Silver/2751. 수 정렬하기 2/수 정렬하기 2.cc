#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> 

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// 시간초과로 인해 피벗을 중간값으로 선정하는 median_of_three 도입 -> 실패
// int median_of_three(vector<int> &arr, int left, int right){
//     int center = (left + right) / 2;

//     if(arr[left] > arr[center]) swap(arr[left], arr[center]);
//     if(arr[left] > arr[right]) swap(arr[left], arr[right]);
//     if(arr[center] > arr[right]) swap(arr[center], arr[right]);

//     return center;
// }

int partition(vector<int> &arr, int l, int r){

    int left = l;
    int right = r;
    int pivot_idx = l + rand() % (right - left + 1);
    int pivot = arr[pivot_idx];

    while(left <= right){

        while(arr[left] < pivot){
            left++;
        }
        while(pivot < arr[right]){
            right--;
        }
    
        if(left <= right){
            swap(arr[left], arr[right]);
            left ++;
            right --;
        }

    }

    return left;

}

void quick_sort(vector<int> &arr, int left, int right){

    if(left >= right){return;}

    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot-1);
    quick_sort(arr, pivot, right);
    
}

int main(){

    int N;

    // 시간 단축을 위함
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    srand(time(NULL));

    cin >> N;
    vector<int> numbers(N);

    for(int i=0; i < N; i++){
        cin >> numbers[i];
    }

    quick_sort(numbers, 0, numbers.size()-1);

    for(int element : numbers){
        printf("%d\n", element);
    }
}