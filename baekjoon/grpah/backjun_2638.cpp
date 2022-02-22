#include <iostream>
#include <queue>
using namespace std;

int cheese[101][101];
int vis[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};


int N, M;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void init_vis(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            vis[i][j] = 0;
}

void init_cheese(){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin>>cheese[i][j];
}

int cheese_count(){
    int count = 0;
     for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(cheese[i][j] == 1) count++;
    return count;
}
void bfs(){
    queue<pair<int,int>> cheese_queue;
    cheese_queue.push({0,0});
    vis[0][0] = 1;

    while(!cheese_queue.empty()){
        int x = cheese_queue.front().first;
        int y = cheese_queue.front().second;
        cheese_queue.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >=0 && ny < M){
                if(cheese[nx][ny] == 0 && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    cheese_queue.push({nx,ny});
                }
                else if(cheese[nx][ny] == 1){
                    vis[nx][ny]+=1;
                }
            }
        }
    }
}
void melt(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(vis[i][j] >= 2 && cheese[i][j] == 1) cheese[i][j] = 0; 
        }
    }
}
int main(){
    int answer = 0;
    init();
    cin >> N >> M;
    init_cheese();
    while(1){
        if(cheese_count() == 0) break;
        else answer++;
    
        init_vis();
        bfs();
        melt();
    }
    cout << answer;
    return 0;
}
