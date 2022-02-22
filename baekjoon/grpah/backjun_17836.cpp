#include <iostream>
#include <queue>
#include <math.h>
#define INF 100*100+1
using namespace std;

int N, M, T , gram_x, gram_y;
int arr[101][101];
int dist[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void set_data(){
    cin >> N >> M >> T;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> arr[i][j];
            dist[i][j] = INF;
            if(arr[i][j] == 2){
                gram_x = i;
                gram_y = j;
            }
        }
    }    
}

void bfs(){
    queue<pair<int,int>> castle;
    castle.push({1,1});
    dist[1][1] = 0;
    while(!castle.empty()){
        int x = castle.front().first;
        int y = castle.front().second;
        castle.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > 0 && nx <= N && ny > 0 && ny <= M){
                if(arr[nx][ny] != 1 && dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    castle.push({nx,ny});
                }
            }
        }
    }

    int min_time = min(dist[N][M], dist[gram_x][gram_y] + N-gram_x + M-gram_y);
    if(min_time > T) cout << "Fail";
    else cout << min_time;
}

int main(){
    init();
    set_data();
    bfs();
    return 0;
}