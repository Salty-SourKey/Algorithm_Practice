//DFS 문제
//중요! DFS는 탐색 후 반드시 원상태로 돌려놓아야 함
//e.g) 방문 유무 && 특수 조건 등등

#include <iostream>
#include <vector>

using namespace std;

int N, K, ans;
int arr[9][9];
int vis[9][9];
int x_pos[4] = {0,0,1,-1};
int y_pos[4] = {1,-1,0,0};

void dfs(int x, int y, int len, int check){
    if(len > ans)
        ans = len;
    int flag = check;
    
    for(int i = 0; i < 4; i++){
        int nx = x + x_pos[i];
        int ny = y + y_pos[i];
        int temp;

        if(nx >= 0 && nx < N && ny >= 0 && ny < N && !vis[nx][ny]){
            temp = arr[nx][ny];
            if(arr[x][y] <= arr[nx][ny]){
                if(arr[nx][ny] - arr[x][y] < K && !flag){
                    arr[nx][ny] = arr[x][y] - 1;
                    flag = 1;
                }
                else continue;
            }
            vis[nx][ny] = 1;
            dfs(nx, ny, len+1, flag);
            vis[nx][ny] = 0;
            
            if(temp != arr[nx][ny]){
                arr[nx][ny] = temp;
                flag = 0;
            }
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int maximum = 0;
        vector<pair<int,int>> top;
        ans = 0;
        cin >> N >> K;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
                if(arr[i][j] > maximum){
                    maximum = arr[i][j];
                    top.clear();
                    top.push_back({i,j});
                }
                else if(arr[i][j] == maximum)
                    top.push_back({i,j});
            }
        }

        for(int i = 0; i < top.size(); i++){
            vis[top[i].first][top[i].second] = 1;
            dfs(top[i].first,top[i].second,1,0);
            vis[top[i].first][top[i].second] = 0;
        }

        cout << "#" << t << " " << ans << endl;
    }
}