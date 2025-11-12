#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

void input(){
    cin >> N;
}

void func(){
    int a, b, c;
    cin >> a >> b >> c;
    
    int pmx0 = a, pmx1 = b, pmx2 = c;
    int pmn0 = a, pmn1 = b, pmn2 = c;

    for (int r = 1; r < N; ++r) {
        cin >> a >> b >> c;

        int cmx0 = a + max(pmx0, pmx1);
        int cmx1 = b + max({pmx0, pmx1, pmx2});
        int cmx2 = c + max(pmx1, pmx2);

        int cmn0 = a + min(pmn0, pmn1);
        int cmn1 = b + min({pmn0, pmn1, pmn2});
        int cmn2 = c + min(pmn1, pmn2);

        pmx0 = cmx0; pmx1 = cmx1; pmx2 = cmx2;
        pmn0 = cmn0; pmn1 = cmn1; pmn2 = cmn2;
    }

    int maxAns = max({pmx0, pmx1, pmx2});
    int minAns = min({pmn0, pmn1, pmn2});
    
    cout << maxAns << " " << minAns << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
}