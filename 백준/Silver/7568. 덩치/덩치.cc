#include <iostream>
#include <vector>

using namespace std;

struct Human {
    int weight;
    int height;
    int rank = 1;
};

int main(){

    int N,weight, height;
    cin >> N;
    vector<Human> human(N);

    for(int i=0; i < N; i++){
        cin >> human[i].weight >> human[i].height;
    }

    for(int j=0; j < N; j++){
        for(int k=0; k < N; k++){
            if (j == k) continue;
            if(human[j].weight < human[k].weight && human[j].height < human[k].height){
                human[j].rank++;
            }
        }
    }

    for(int z=0; z < N; z++){
        cout << human[z].rank << " ";
    }

}
