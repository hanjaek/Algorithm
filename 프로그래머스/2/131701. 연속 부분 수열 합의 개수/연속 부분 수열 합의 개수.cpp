#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    set<int> s;
    
    for(int len = 1; len <= n; len++){
        for(int start = 0; start < n; start++){
            int sum = 0;
            for(int idx = 0; idx < len; idx++){
                sum += (elements[(start + idx) % n]);
            }
            s.insert(sum);
        }
    }
    return s.size();
}