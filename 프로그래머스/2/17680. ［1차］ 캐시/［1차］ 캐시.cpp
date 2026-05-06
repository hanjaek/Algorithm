#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0) return cities.size() * 5;
    
    int answer = 0;
    vector<string> cache;
    
    for(string city: cities){
        
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        vector<string>::iterator it;
        it = find(cache.begin(), cache.end(), city);
        
        if(it != cache.end()){
            answer++;
            
            cache.erase(it);
            cache.push_back(city);
        }
        else{
            answer += 5;
            
            if(cache.size() == cacheSize){
                cache.erase(cache.begin());
            }
            cache.push_back(city);
        }
    }
    
    return answer;
}