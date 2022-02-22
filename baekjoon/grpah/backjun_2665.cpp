#include <iostream>
#include <queue>
#define INF 50*50+1

using namespace std;

int N;
char arr[51][51];
int cnt[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0 , 1, -1};

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void set_data(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[i][j];
            cnt[i][j] = INF;
        }
    }
}

void bfs(){
    queue<pair<int,int>> maze;
    maze.push({0,0});
    cnt[0][0] = 0;
    while(!maze.empty()){
        int x = maze.front().first;
        int y = maze.front().second;
        maze.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                if(arr[nx][ny] == '1' && cnt[nx][ny] > cnt[x][y]){
                    cnt[nx][ny] = cnt[x][y];
                    maze.push({nx,ny});
                }
                else if(arr[nx][ny] == '0' && cnt[nx][ny] > cnt[x][y] + 1){
                        cnt[nx][ny] = cnt[x][y] + 1;
                        maze.push({nx, ny});
                }
            }        
        }
    }
    cout << cnt[N-1][N-1];
    return;
}

int main(){
    init();
    set_data();
    bfs();
    return 0;
}