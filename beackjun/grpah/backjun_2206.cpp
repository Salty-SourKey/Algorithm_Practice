#include <iostream>
#include <string>
#include <queue>
using namespace std;
//BFS는 방문처리가 반드시 필요하다!!
int arr[1002][1002];
int vis[1002][1002];
int break_vis[1002][1002];
string input[1002];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
typedef struct node{
    int x;
    int y;
    int move;
    bool one;
} Node;

int bfs(){
    queue<Node> map;
    Node temp = {0, 0, 1, false};
    map.push(temp);
    while(!map.empty()){
        int x = map.front().x;
        int y = map.front().y;
        int count = map.front().move;
        bool check = map.front().one;
        map.pop();
        if(x == N-1 && y == M-1) return count;
        else{
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                    if(!check){
                        vis[nx][ny] = 1;
                        break_vis[nx][ny] = 1;
                        if(arr[nx][ny] == 0 && vis[nx][ny] == 0) map.push(Node{nx,ny,count+1,check});
                        else if(arr[nx][ny] == 1 && vis[nx][ny] == 0) map.push(Node{nx,ny,count+1,!check});
                        
                    }
                    else{
                        if(arr[nx][ny] == 0 && break_vis[nx][ny] == 0){
                            break_vis[nx][ny] = 1;
                            map.push(Node{nx,ny,count+1,check});
                        }
                    }
                }
            }
        }
    }
    return -1;
}
int main(){
    init();
    cin >> N >> M;
    char temp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> temp;
            arr[i][j] = temp - '0';
        }
    }
    cout << bfs();
    return 0;

}