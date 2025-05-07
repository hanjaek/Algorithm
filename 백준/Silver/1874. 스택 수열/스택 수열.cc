#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<char> result;
    vector<int> stack;
    int number = 1;

    cin >> N;
    vector<int> numbers(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    for (int i = 0; i < numbers.size(); i++) {
        int target = numbers[i];

        while (number <= target) {
            stack.push_back(number);
            result.push_back('+');
            number++;
        }

        if (!stack.empty() && stack.back() == target) {
            stack.pop_back();
            result.push_back('-');
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    for (auto element : result) {
        cout << element << "\n";
    }

}
