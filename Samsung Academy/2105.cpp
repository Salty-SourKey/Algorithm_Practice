//가지치기 + DFS
//회전의 방향은 아래로 시계, 아래로 반시계만 고려하면 된다는것이 매우 중요

#include <iostream>
#include <math.h>

using namespace std;

int arr[20][20];
int vis[20][20];
int cnt[101];

int x_pos[4] = {-1, -1, 1, 1};
int y_pos[4] = {-1, 1, -1, 1};

int anti_pair[4] = {2, 0, 3, 1};
int o_pair[4] = {1, 3, 0, 2};

int ans, N;

void input(){
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];
}

void rotate_anticlock(int num, int x, int y, int dir, int start_x, int start_y){
    int nx, ny;
    nx = x + x_pos[dir];
    ny = y + y_pos[dir];
    if(nx >= 0 && nx < N && ny >= 0 && ny < N){
        if(nx == start_x && ny == start_y && dir == 2){
            ans = max(ans, num);
            return;
        }
        if(!cnt[arr[nx][ny]] && !vis[nx][ny]){
            cnt[arr[nx][ny]] = 1;
            vis[nx][ny] = 1;
            rotate_anticlock(num+1, nx, ny, dir, start_x, start_y);
            cnt[arr[nx][ny]] = 0;
            vis[nx][ny] = 0;
        }
    }

    nx = x + x_pos[anti_pair[dir]];
    ny = y + y_pos[anti_pair[dir]];
    if(dir != 2 && nx >= 0 && nx < N && ny >= 0 && ny < N){
        if(nx == start_x && ny == start_y && anti_pair[dir] == 0){
            ans = max(ans, num);
            return;
        }
        if(!cnt[arr[nx][ny]] && !vis[nx][ny]){
            cnt[arr[nx][ny]] = 1;
            vis[nx][ny] = 1;
            rotate_anticlock(num+1, nx, ny, anti_pair[dir], start_x, start_y);
            cnt[arr[nx][ny]] = 0;
            vis[nx][ny] = 0;
        }
    }
}

void rotate_clock(int num, int x, int y, int dir, int start_x, int start_y){
    int nx, ny;
    nx = x + x_pos[dir];
    ny = y + y_pos[dir];
    if(nx >= 0 && nx < N && ny >= 0 && ny < N){
        if(nx == start_x && ny == start_y && dir == 3){
            ans = max(ans, num);
            return;
        }
        if(!cnt[arr[nx][ny]] && !vis[nx][ny]){
            cnt[arr[nx][ny]] = 1;
            vis[nx][ny] = 1;
            rotate_clock(num+1, nx, ny, dir, start_x, start_y);
            cnt[arr[nx][ny]] = 0;
            vis[nx][ny] = 0;
        }
    }

    nx = x + x_pos[o_pair[dir]];
    ny = y + y_pos[o_pair[dir]];
    if(nx >= 0 && nx < N && ny >= 0 && ny < N && dir != 3){
        if(nx == start_x && ny == start_y && o_pair[dir] == 3){
            ans = max(ans, num);
            return;
        }
        if(!cnt[arr[nx][ny]] && !vis[nx][ny]){
            cnt[arr[nx][ny]] = 1;
            vis[nx][ny] = 1;
            rotate_clock(num+1, nx, ny, o_pair[dir], start_x, start_y);
            cnt[arr[nx][ny]] = 0;
            vis[nx][ny] = 0;
        }
    }
}

void solve(){
    for(int i = 1; i < N-1; i++){
        for(int j = 0; j < N; j++){
            vis[i][j] = 1;
            cnt[arr[i][j]] = 1;
            rotate_anticlock(1, i, j, 3, i, j);
            rotate_clock(1, i, j, 2, i, j);
            vis[i][j] = 0;
            cnt[arr[i][j]] = 0;    
        }
    }
}


int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        ans = 0;
        input();
        solve();
        if(ans == 0) ans = -1;
        cout << "#" << t << " " << ans << endl;
    }
}