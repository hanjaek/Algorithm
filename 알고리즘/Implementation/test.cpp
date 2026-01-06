void rotate_sides(char pivot, char dir){
    char t1, t2, t3;

    if(pivot == 'U'){
        t1 = cube[2][0][0]; t2 = cube[2][0][1]; t3 = cube[2][0][2];
        if(dir == '+'){
            cube[2][0][0]=cube[4][0][0]; cube[2][0][1]=cube[4][0][1]; cube[2][0][2]=cube[4][0][2];
            cube[4][0][0]=cube[3][0][0]; cube[4][0][1]=cube[3][0][1]; cube[4][0][2]=cube[3][0][2];
            cube[3][0][0]=cube[5][0][0]; cube[3][0][1]=cube[5][0][1]; cube[3][0][2]=cube[5][0][2];
            cube[5][0][0]=t1; cube[5][0][1]=t2; cube[5][0][2]=t3;
        }else{
            cube[2][0][0]=cube[5][0][0]; cube[2][0][1]=cube[5][0][1]; cube[2][0][2]=cube[5][0][2];
            cube[5][0][0]=cube[3][0][0]; cube[5][0][1]=cube[3][0][1]; cube[5][0][2]=cube[3][0][2];
            cube[3][0][0]=cube[4][0][0]; cube[3][0][1]=cube[4][0][1]; cube[3][0][2]=cube[4][0][2];
            cube[4][0][0]=t1; cube[4][0][1]=t2; cube[4][0][2]=t3;
        }
    }
    else if(pivot == 'D'){
        t1 = cube[2][2][0]; t2 = cube[2][2][1]; t3 = cube[2][2][2];
        if(dir == '+'){
            cube[2][2][0]=cube[5][2][0]; cube[2][2][1]=cube[5][2][1]; cube[2][2][2]=cube[5][2][2];
            cube[5][2][0]=cube[3][2][0]; cube[5][2][1]=cube[3][2][1]; cube[5][2][2]=cube[3][2][2];
            cube[3][2][0]=cube[4][2][0]; cube[3][2][1]=cube[4][2][1]; cube[3][2][2]=cube[4][2][2];
            cube[4][2][0]=t1; cube[4][2][1]=t2; cube[4][2][2]=t3;
        }else{
            cube[2][2][0]=cube[4][2][0]; cube[2][2][1]=cube[4][2][1]; cube[2][2][2]=cube[4][2][2];
            cube[4][2][0]=cube[3][2][0]; cube[4][2][1]=cube[3][2][1]; cube[4][2][2]=cube[3][2][2];
            cube[3][2][0]=cube[5][2][0]; cube[3][2][1]=cube[5][2][1]; cube[3][2][2]=cube[5][2][2];
            cube[5][2][0]=t1; cube[5][2][1]=t2; cube[5][2][2]=t3;
        }
    }
    else if(pivot == 'F'){
        t1 = cube[0][2][0]; t2 = cube[0][2][1]; t3 = cube[0][2][2];
        if(dir == '+'){
            cube[0][2][0]=cube[4][2][2]; cube[0][2][1]=cube[4][1][2]; cube[0][2][2]=cube[4][0][2];
            cube[4][0][2]=cube[1][0][0]; cube[4][1][2]=cube[1][0][1]; cube[4][2][2]=cube[1][0][2];
            cube[1][0][0]=cube[5][2][0]; cube[1][0][1]=cube[5][1][0]; cube[1][0][2]=cube[5][0][0];
            cube[5][0][0]=t1; cube[5][1][0]=t2; cube[5][2][0]=t3;
        }else{
            cube[0][2][0]=cube[5][0][0]; cube[0][2][1]=cube[5][1][0]; cube[0][2][2]=cube[5][2][0];
            cube[5][0][0]=cube[1][0][2]; cube[5][1][0]=cube[1][0][1]; cube[5][2][0]=cube[1][0][0];
            cube[1][0][0]=cube[4][0][2]; cube[1][0][1]=cube[4][1][2]; cube[1][0][2]=cube[4][2][2];
            cube[4][0][2]=t3; cube[4][1][2]=t2; cube[4][2][2]=t1;
        }
    }
    else if(pivot == 'B'){
        t1 = cube[0][0][0]; t2 = cube[0][0][1]; t3 = cube[0][0][2];
        if(dir == '+'){
            cube[0][0][0]=cube[5][0][2]; cube[0][0][1]=cube[5][1][2]; cube[0][0][2]=cube[5][2][2];
            cube[5][0][2]=cube[1][2][2]; cube[5][1][2]=cube[1][2][1]; cube[5][2][2]=cube[1][2][0];
            cube[1][2][0]=cube[4][0][0]; cube[1][2][1]=cube[4][1][0]; cube[1][2][2]=cube[4][2][0];
            cube[4][0][0]=t3; cube[4][1][0]=t2; cube[4][2][0]=t1;
        }else{
            cube[0][0][0]=cube[4][2][0]; cube[0][0][1]=cube[4][1][0]; cube[0][0][2]=cube[4][0][0];
            cube[4][0][0]=cube[1][2][0]; cube[4][1][0]=cube[1][2][1]; cube[4][2][0]=cube[1][2][2];
            cube[1][2][0]=cube[5][2][2]; cube[1][2][1]=cube[5][1][2]; cube[1][2][2]=cube[5][0][2];
            cube[5][0][2]=t1; cube[5][1][2]=t2; cube[5][2][2]=t3;
        }
    }
    else if(pivot == 'L'){
        t1 = cube[0][0][0]; t2 = cube[0][1][0]; t3 = cube[0][2][0];
        if(dir == '+'){
            cube[0][0][0]=cube[3][2][2]; cube[0][1][0]=cube[3][1][2]; cube[0][2][0]=cube[3][0][2];
            cube[3][0][2]=cube[1][2][0]; cube[3][1][2]=cube[1][1][0]; cube[3][2][2]=cube[1][0][0];
            cube[1][0][0]=cube[2][0][0]; cube[1][1][0]=cube[2][1][0]; cube[1][2][0]=cube[2][2][0];
            cube[2][0][0]=t1; cube[2][1][0]=t2; cube[2][2][0]=t3;
        }else{
            cube[0][0][0]=cube[2][0][0]; cube[0][1][0]=cube[2][1][0]; cube[0][2][0]=cube[2][2][0];
            cube[2][0][0]=cube[1][0][0]; cube[2][1][0]=cube[1][1][0]; cube[2][2][0]=cube[1][2][0];
            cube[1][0][0]=cube[3][2][2]; cube[1][1][0]=cube[3][1][2]; cube[1][2][0]=cube[3][0][2];
            cube[3][0][2]=t3; cube[3][1][2]=t2; cube[3][2][2]=t1;
        }
    }
    else if(pivot == 'R'){
        t1 = cube[0][0][2]; t2 = cube[0][1][2]; t3 = cube[0][2][2];
        if(dir == '+'){
            cube[0][0][2]=cube[2][0][2]; cube[0][1][2]=cube[2][1][2]; cube[0][2][2]=cube[2][2][2];
            cube[2][0][2]=cube[1][0][2]; cube[2][1][2]=cube[1][1][2]; cube[2][2][2]=cube[1][2][2];
            cube[1][0][2]=cube[3][2][0]; cube[1][1][2]=cube[3][1][0]; cube[1][2][2]=cube[3][0][0];
            cube[3][0][0]=t3; cube[3][1][0]=t2; cube[3][2][0]=t1;
        }else{
            cube[0][0][2]=cube[3][2][0]; cube[0][1][2]=cube[3][1][0]; cube[0][2][2]=cube[3][0][0];
            cube[3][0][0]=cube[1][2][2]; cube[3][1][0]=cube[1][1][2]; cube[3][2][0]=cube[1][0][2];
            cube[1][0][2]=cube[2][0][2]; cube[1][1][2]=cube[2][1][2]; cube[1][2][2]=cube[2][2][2];
            cube[2][0][2]=t1; cube[2][1][2]=t2; cube[2][2][2]=t3;
        }
    }
}
