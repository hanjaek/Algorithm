#include <iostream>
#include <map>

using namespace std;

int main(){

    int T,N;

    cin >> T;
    for(int i=0; i < T; i++){

        map<string, int> clothes;
        int result = 1;
        cin >> N;

        for(int j=0; j < N; j++){
            string name, type;
            cin >> name >> type;

            clothes[type]++;
        }

        for(auto &element : clothes){
            result *= (element.second + 1); // 1은 각 type마다 안입는 경우 -> 모자는 썼지만, 안경은 안쓰는 경우
        }

        cout << result - 1 << "\n"; // -1은 알몸인 경우 (모든 type을 안입는 경우의 수 제거)

    }

}