#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

//[0][0] ~ [N][M] 거리와 [N][M] ~ [0][0] 거리를 구하게 BFS를 두번
#define INF 1000*1000+1

char arr[1002][1002];
int dist1[1002][1002];
int dist2[1002][1002];

int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void bfs(){
    queue<pair<int,int>> map;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            dist1[i][j] = INF;
            dist2[i][j] = INF;
        }
    }
    map.push({0,0});
    dist1[0][0] = 1;
    while(!map.empty()){
        int x = map.front().first;
        int y = map.front().second;
        map.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                if(arr[nx][ny] == '0' && dist1[nx][ny] > dist1[x][y] + 1){
                    dist1[nx][ny] = dist1[x][y] + 1;
                    map.push({nx,ny});
                }
            }
        }
    }
    map.push({N-1,M-1});
    dist2[N-1][M-1] = 1;
    while(!map.empty()){
        int x = map.front().first;
        int y = map.front().second;
        map.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                if(arr[nx][ny] == '0' && dist2[nx][ny] > dist2[x][y] + 1){
                    dist2[nx][ny] = dist2[x][y] + 1;
                    map.push({nx,ny});
                }
            }
        }
    }
}

int calc(){
    init();
    int count = dist1[N-1][M-1];
    int min_dist1;
    int min_dist2;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(arr[i][j] == '1'){
                min_dist1 = INF;
                min_dist2 = INF;
                for(int k = 0; k < 4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];    
                    if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                        min_dist1 = min(min_dist1, dist1[nx][ny]);
                        min_dist2 = min(min_dist2, dist2[nx][ny]);
                    }
                }
                count = min(count, min_dist1 + min_dist2 + 1);
            }
        }
    }
    if(count == INF) return -1;
    return count;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> arr[i][j];
    bfs();
    cout << calc();
    return 0;
}
