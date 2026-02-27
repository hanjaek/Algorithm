#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define endl "\n"

int Q, N, M;
set<int> lamps;
vector<int> lamps_idx;
vector<bool> lamps_state;
multiset<int> need_power;

struct Gap{
    int len, L, R;
};

struct Gap_cmp{
    bool operator()(const Gap &a, const Gap &b){
        if(a.len != b.len) return a.len < b.len;
        return a.L > b.L;
    }
};

priority_queue<Gap, vector<Gap>, Gap_cmp> pq;

void add_power(int L, int R){
    need_power.insert(R-L);
}

void del_power(int L, int R){
    auto it = need_power.find(R-L);
    if(it != need_power.end()) need_power.erase(it);
}

bool is_check(int L, int R){
    auto it_l = lamps.find(L);
    if(it_l == lamps.end()) return false;

    auto it_r = next(it_l);
    if(it_r == lamps.end()) return false;

    return (*it_r == R);
}

Gap get_best_gap(){
    while(!pq.empty()){
        auto g = pq.top();
        if(is_check(g.L, g.R)) return g;
        pq.pop();
    }
    return {0, 0, 0};
}

void init(){
    if(lamps.size() < 2) return;

    auto it = lamps.begin();
    auto next_it = next(it);

    for(; next_it != lamps.end(); it++, next_it++){
        int L = *it;
        int R = *next_it;
        pq.push({R-L, L, R});
        add_power(L, R);
    }
    
}

void lamp_add(){
    auto bg = get_best_gap();
    int L = bg.L;
    int R = bg.R;

    int new_lamp = (R + L + 1) / 2;

    lamps_idx.push_back(new_lamp);
    lamps_state.push_back(1);

    del_power(L, R);
    lamps.insert(new_lamp);

    add_power(L, new_lamp);
    add_power(new_lamp, R);

    pq.push({new_lamp - L, L, new_lamp});
    pq.push({R - new_lamp, new_lamp, R});
}

void lamp_delete(int d){
    if(d <= 0 || d >= (int)lamps_idx.size()) return;
    if(!lamps_state[d]) return;

    lamps_state[d] = 0;
    int d_lamp = lamps_idx[d];

    auto it = lamps.find(d_lamp);
    if(it == lamps.end()) return;

    auto it_left = (it == lamps.begin() ? lamps.end() : prev(it));
    auto it_right = next(it);

    if(it_left != lamps.end()) del_power(*it_left, d_lamp);
    if(it_right != lamps.end()) del_power(d_lamp, *it_right);
    lamps.erase(it);

    if(it_left != lamps.end() && it_right != lamps.end()){
        add_power(*it_left, *it_right);
        pq.push({*it_right - *it_left, *it_left, *it_right});
    }
}

void power_calc(){
    int result = 0;

    if(!lamps.empty()){
        int first = *lamps.begin();
        int last = *prev(lamps.end());

        result = max(result, 2*(first - 1));
        result = max(result, 2*(N - last));
    }

    if(!need_power.empty()){
        result = max(result, *need_power.rbegin());
    }

    cout << result << endl;
}

void command(int c, int d){
    if(c == 200){
        lamp_add();
    }
    else if(c == 300){
        lamp_delete(d);
    }
    else if(c == 400){
        power_calc();
    }
    else{
        cout << "유효 X" << endl;
    }
}

void input(){
    int init_type;

    cin >> Q;
    cin >> init_type >> N >> M;

    // 1-index
    lamps_idx.push_back(-1);
    lamps_state.push_back(0);

    for(int i=0; i < M; i++){
        int x;
        cin >> x;
        lamps.insert(x);
        lamps_idx.push_back(x);
        lamps_state.push_back(1);
    }

    init();
}

void func(){
    for(int i=0; i < Q-1; i++){
        int c;
        int d = 0;
        cin >> c;
        if(c == 300){
            cin >> d;
        }
        command(c, d);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    input();
    func();
    return 0;
}