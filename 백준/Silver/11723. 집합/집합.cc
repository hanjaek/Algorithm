#include <iostream>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, bitmask = 0;
    string command;
    int number;

    cin >> N;

    for (int i = 0; i < N; i++) {

        cin >> command;

        if (command == "add") {
            cin >> number;
            bitmask |= (1 << (number - 1));
        }
        else if (command == "remove") {
            cin >> number;
            bitmask &= ~(1 << (number - 1));
        }
        else if (command == "check") {
            cin >> number;
            cout << ((bitmask & (1 << (number - 1))) ? 1 : 0) << "\n";
        }
        else if (command == "toggle") {
            cin >> number;
            bitmask ^= (1 << (number - 1));
        }
        else if (command == "all") {
            bitmask = (1 << 20) - 1; 
        }
        else if (command == "empty") {
            bitmask = 0;
        }

    }

}
