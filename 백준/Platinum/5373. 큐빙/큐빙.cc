#include <iostream>
#include <vector>

using namespace std;

int T;
char cube[6][3][3];

void init_cube(){
    char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};

    for(int f=0; f < 6; f++){
        for(int r=0; r < 3; r++){
            for(int c=0; c < 3; c++){
                cube[f][r][c] = color[f];
            }
        }
    }
}

int face_index(char pivot){
    if(pivot == 'U') return 0;
    else if(pivot == 'D') return 1;
    else if(pivot == 'F') return 2;
    else if(pivot == 'B') return 3;
    else if(pivot == 'L') return 4;
    else return 5;

}

void rotate_face(int pivot, char dir){
    char tmp[3][3];
    for(int r=0; r<3; r++){
        for(int c=0; c<3; c++){
            tmp[r][c] = cube[pivot][r][c];
        }
    }

    for(int r=0; r<3; r++){
        for(int c=0; c<3; c++){
            cube[pivot][r][c] = (dir == '+') ? tmp[2-c][r] : tmp[c][2-r];
        }
    }
}

void rotate_sides(char pivot, char dir){
    char t[3];

    int U = 0; int D = 1; int F = 2; int B = 3; int L = 4; int R = 5;

    if(pivot=='U'){
        for(int i=0;i<3;i++) t[i]=cube[F][0][i];
        if(dir=='+'){
            for(int i=0;i<3;i++) cube[F][0][i]=cube[R][0][i];
            for(int i=0;i<3;i++) cube[R][0][i]=cube[B][0][i];
            for(int i=0;i<3;i++) cube[B][0][i]=cube[L][0][i];
            for(int i=0;i<3;i++) cube[L][0][i]=t[i];
        }else{
            for(int i=0;i<3;i++) cube[F][0][i]=cube[L][0][i];
            for(int i=0;i<3;i++) cube[L][0][i]=cube[B][0][i];
            for(int i=0;i<3;i++) cube[B][0][i]=cube[R][0][i];
            for(int i=0;i<3;i++) cube[R][0][i]=t[i];
        }
    }
    else if(pivot=='D'){
        for(int i=0;i<3;i++) t[i]=cube[F][2][i];
        if(dir=='+'){
            for(int i=0;i<3;i++) cube[F][2][i]=cube[L][2][i];
            for(int i=0;i<3;i++) cube[L][2][i]=cube[B][2][i];
            for(int i=0;i<3;i++) cube[B][2][i]=cube[R][2][i];
            for(int i=0;i<3;i++) cube[R][2][i]=t[i];
        }else{
            for(int i=0;i<3;i++) cube[F][2][i]=cube[R][2][i];
            for(int i=0;i<3;i++) cube[R][2][i]=cube[B][2][i];
            for(int i=0;i<3;i++) cube[B][2][i]=cube[L][2][i];
            for(int i=0;i<3;i++) cube[L][2][i]=t[i];
        }
    }
    else if(pivot=='F'){
        for(int i=0;i<3;i++) t[i]=cube[U][2][i];
        if(dir=='+'){
            for(int i=0;i<3;i++) cube[U][2][i]=cube[L][2-i][2];
            for(int i=0;i<3;i++) cube[L][2-i][2]=cube[D][0][2-i];
            for(int i=0;i<3;i++) cube[D][0][2-i]=cube[R][i][0];
            for(int i=0;i<3;i++) cube[R][i][0]=t[i];
        }else{
            for(int i=0;i<3;i++) t[i]=cube[D][0][i];
            for(int i=0;i<3;i++) cube[D][0][i]=cube[L][i][2];
            for(int i=0;i<3;i++) cube[L][i][2]=cube[U][2][2-i];
            for(int i=0;i<3;i++) cube[U][2][2-i]=cube[R][2-i][0];
            for(int i=0;i<3;i++) cube[R][2-i][0]=t[i];
        }
    }
    else if(pivot=='B'){
        if(dir=='+'){
            for(int i=0;i<3;i++) t[i]=cube[D][2][i];
            for(int i=0;i<3;i++) cube[D][2][i]=cube[L][i][0];
            for(int i=0;i<3;i++) cube[L][2-i][0]=cube[U][0][i];
            for(int i=0;i<3;i++) cube[U][0][i]=cube[R][i][2];
            for(int i=0;i<3;i++) cube[R][2-i][2]=t[i];
        }else{
            for(int i=0;i<3;i++) t[i]=cube[D][2][2-i];
            for(int i=0;i<3;i++) cube[D][2][2-i]=cube[R][i][2];
            for(int i=0;i<3;i++) cube[R][i][2]=cube[U][0][i];
            for(int i=0;i<3;i++) cube[U][0][2-i]=cube[L][i][0];
            for(int i=0;i<3;i++) cube[L][2-i][0]=t[i];
        }
    }
    else if(pivot=='L'){
        for(int i=0;i<3;i++) t[i]=cube[U][i][0];
        if(dir=='+'){
            for(int i=0;i<3;i++) cube[U][i][0]=cube[B][2-i][2];
            for(int i=0;i<3;i++) cube[B][2-i][2]=cube[D][i][0];
            for(int i=0;i<3;i++) cube[D][i][0]=cube[F][i][0];
            for(int i=0;i<3;i++) cube[F][i][0]=t[i];
        }else{
            for(int i=0;i<3;i++) cube[U][i][0]=cube[F][i][0];
            for(int i=0;i<3;i++) cube[F][i][0]=cube[D][i][0];
            for(int i=0;i<3;i++) cube[D][i][0]=cube[B][2-i][2];
            for(int i=0;i<3;i++) cube[B][2-i][2]=t[i];
        }
    }
    else if(pivot=='R'){
        if(dir=='+'){
            for(int i=0;i<3;i++) t[i]=cube[D][i][2];
            for(int i=0;i<3;i++) cube[D][i][2]=cube[B][2-i][0];
            for(int i=0;i<3;i++) cube[B][2-i][0]=cube[U][i][2];
            for(int i=0;i<3;i++) cube[U][i][2]=cube[F][i][2];
            for(int i=0;i<3;i++) cube[F][i][2]=t[i];
        }else{
            for(int i=0;i<3;i++) t[i]=cube[U][i][2];
            for(int i=0;i<3;i++) cube[U][i][2]=cube[B][2-i][0];
            for(int i=0;i<3;i++) cube[B][2-i][0]=cube[D][i][2];
            for(int i=0;i<3;i++) cube[D][i][2]=cube[F][i][2];
            for(int i=0;i<3;i++) cube[F][i][2]=t[i];
        }
    }
}

void move_cube(char pivot, char dir){
    rotate_sides(pivot, dir);
    rotate_face(face_index(pivot), dir);
}

void input(){
    int n;
    string s;
    init_cube();

    cin >> n;
    for(int i=0; i < n; i++){
        cin >> s;
        move_cube(s[0], s[1]);
    }
}

void func(){
    for(int r=0; r<3; r++){
        for(int c=0; c<3; c++){
            cout << cube[0][r][c];
        }
        cout << "\n";
    }
    // cout << "========================" << "\n";
    // for(int c=0;c<3;c++) cout<<cube[2][0][c]; cout<<"\n"; // F
    // for(int c=0;c<3;c++) cout<<cube[5][0][c]; cout<<"\n"; // R
    // for(int c=0;c<3;c++) cout<<cube[3][0][c]; cout<<"\n"; // B
    // for(int c=0;c<3;c++) cout<<cube[4][0][c]; cout<<"\n"; // L
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    while(T--){
        input();
        func();
    }
}