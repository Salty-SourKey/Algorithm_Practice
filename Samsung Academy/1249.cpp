//간단한 BFS 문제

#include <iostream>
#include <queue>
#define INF 100000000
using namespace std;


int arr[101][101];
int cnt[101][101];
int x[4] = {0,0,1,-1};
int y[4] = {1,-1,0,0};

void bfs(int N){
    queue<pair<int,int>> pos;
    pos.push({0,0});
    cnt[0][0] = 0;
    while(!pos.empty()){
        int _x = pos.front().first;
        int _y = pos.front().second;
        pos.pop();
        for(int i = 0; i < 4; i++){
            int nx = _x + x[i];
            int ny = _y + y[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                if(cnt[_x][_y] + arr[nx][ny] < cnt[nx][ny]){
                    cnt[nx][ny] = cnt[_x][_y] + arr[nx][ny];
                    pos.push({nx,ny});
                }
            }
        }

    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        char input;
        
        cin >> N;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> input;
                arr[i][j] = input - 48;
            }
        }       

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cnt[i][j] = INF;
        }
        
    
        bfs(N);

        cout << "#" << t << " " << cnt[N-1][N-1] << endl;
    }
}