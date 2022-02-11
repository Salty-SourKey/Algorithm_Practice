#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>

#define RIGHT 0
#define LEFT 1
#define DOWN 2
#define UP 3

using namespace std;


char op[21][21];
int dict[21][21][4][17];

int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};

pair<int,int> check(int x, int y, int R, int C){
    if(x < 0)
        return {R-1, y};
    else if(x >= R)
        return {0, y};
    else if(y < 0)
        return {x, C-1};
    else if(y >= C)
        return {x, 0};
    else return {x,y};
}

void dfs(int _x, int _y, int mem, int dir, int R, int C){
    char c = op[_x][_y];
    int nx;
    int ny;
    if(c == '<') dir = LEFT;
    else if(c == '>') dir = RIGHT;
    else if(c == '^') dir = UP;
    else if(c == 'v') dir = DOWN;
    else if(c == '_'){
        if(mem) dir = LEFT;
        else dir = RIGHT;
    }
    else if(c == '|'){
        if(mem) dir = UP;
        else dir = DOWN;
    }
    else if(c == '+'){
        mem += 1;
        if(mem == 16) 
            mem = 0;
    }
    else if(c == '-'){
        mem -= 1;
        if(mem == -1)
            mem = 15;
    }
    else if(c == '?'){}
    else if(c == '@'){}
    else if(c == '.'){}
    else mem = c - 48;

    if(c == '@'){
        dict[_x][_y][dir][mem]++;
        return;
    }
    else if(c == '?'){
        for(int i = 0; i < 4; i++){
            dir = i;
            nx = check(_x+x[i], _y+y[i], R, C).first;
            ny = check(_x+x[i], _y+y[i], R, C).second;
            if(!dict[_x][_y][dir][mem]){
                dict[_x][_y][dir][mem]++;
                dfs(nx, ny, mem, dir, R, C);    
            }
        }
    }
    else{
        nx = check(_x+x[dir], _y+y[dir], R, C).first;
        ny = check(_x+x[dir], _y+y[dir], R, C).second; 
        if(!dict[_x][_y][dir][mem]){
            dict[_x][_y][dir][mem]++;
            dfs(nx, ny, mem, dir, R, C);     
        }
        else return;
    }   
}


int main(){
    int T, ans;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int R, C;
        vector<int> target_x;
        vector<int> target_y;
        ans = 0;
        cin >> R >> C;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                cin >> op[i][j];
                if(op[i][j] == '@'){
                    target_x.push_back(i);
                    target_y.push_back(j);
                }
            }
        }

        dfs(0,0,0,RIGHT, R, C);
        for(int k = 0; k < target_x.size(); k++)
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 16; j++)
                    ans += dict[target_x[k]][target_y[k]][i][j];

        if(ans)
            cout << "#" << t << " YES" << endl;
        else
            cout << "#" << t << " NO" << endl;
        
        memset(dict, 0, sizeof(dict));
    }    
    return 0;
}