#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define endl "\n"

int N, M;
vector<vector<int>> grid;

struct Box{
    int k, h, w, c, r;
    bool alive;
};

struct cmp{
    bool operator()(const Box &a, const Box &b) const{
        return a.k < b.k;
    }
};

vector<Box> boxes;

void erase_box(int i){
    for(int r = boxes[i].r; r < boxes[i].r + boxes[i].h; r++){
        for(int c = boxes[i].c; c < boxes[i].c + boxes[i].w; c++){
            grid[r][c] = 0;
        }
    }
}

void draw_box(int i){
    for(int r = boxes[i].r; r < boxes[i].r + boxes[i].h; r++){
        for(int c = boxes[i].c; c < boxes[i].c + boxes[i].w; c++){
            grid[r][c] = boxes[i].k;
        }
    }
}

bool check_out(int i, int dir){
    if(!boxes[i].alive) return false;

    int top = boxes[i].r;
    int bottom = boxes[i].r + boxes[i].h - 1;
    int left = boxes[i].c;
    int right = boxes[i].c + boxes[i].w - 1;

    for(int r=top; r <= bottom; r++){
        if(dir==0){
            for(int c=0; c < left; c++){
                if(grid[r][c] != 0) return false;
            }
        }
        else{
            for(int c=right+1; c < N; c++){
                if(grid[r][c] != 0) return false;
            }
        }
    }
    return true;
}

bool check_drop(int i){
    int top = boxes[i].r;
    int left = boxes[i].c;
    int bottom = top + boxes[i].h - 1;
    int right = left + boxes[i].w - 1;

    if(bottom + 1 >= N) return false;

    for(int check = left; check <= right; check++){
        if(grid[bottom+1][check] != 0) return false;
    }
    return true;
}

void box_drop(int i){

    erase_box(i);

    while(check_drop(i)){
        boxes[i].r++;
    }

    draw_box(i);
}

void stabilize(){
    while(true){
        bool moved = false;

        for(int i=0; i < M; i++){
            if(!boxes[i].alive) continue;

            int old_r = boxes[i].r;
            box_drop(i);

            if(boxes[i].r != old_r) moved = true;
        }
        if(!moved) break;
    }
}

int pick_box(int dir){
    int min_k = -1;
    for(int i=0; i < M; i++){
        if(check_out(i, dir)){
            if(min_k == -1 || boxes[min_k].k > boxes[i].k){
                min_k = i;
            }
        }
    }
    return min_k;
}

void remove_box(int i){
    erase_box(i);
    boxes[i].alive = false;
    cout << boxes[i].k << endl;
    stabilize();
}

void input(){
    cin >> N >> M;
    grid.resize(N, vector<int>(N, 0));
    boxes.resize(M);
    
    for(int i=0; i < M; i++){
        int k, h, w, c;
        cin >> k >> h >> w >> c;
        c--;
        boxes[i] = {k, h, w, c, 0, true};
        draw_box(i);
        box_drop(i);
    }
}

void func(){
    int alive_cnt = M;

    while(alive_cnt > 0){
        bool removed = false;

        int left = pick_box(0);
        if(left != -1){
            remove_box(left);
            alive_cnt--;
            removed = true;
        }

        int right = pick_box(1);
        if(right != -1){
            remove_box(right);
            alive_cnt--;
            removed = true;
        }

        if(!removed) break;
    } 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
    return 0;
}