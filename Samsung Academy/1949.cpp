//전체탐색 -> 매우 느림
//DP 또는 DFS로 속도 올릴 수 있음

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int x_pos[4] = {0,0,1,-1};
int y_pos[4] = {1,-1,0,0};
int arr[9][9];
int N, K, ans;

void bfs(int x, int y, int k, int i, int j){
    arr[i][j] -= k;
    queue<vector<int>> q;
    q.push(vector<int>{x,y,1});
    while(!q.empty()){
        int x_ = q.front()[0];
        int y_ = q.front()[1];
        int dist = q.front()[2];
        ans = max(ans, dist);
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x_ + x_pos[i];
            int ny = y_ + y_pos[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                if(arr[x_][y_] > arr[nx][ny])
                    q.push(vector<int>{nx,ny,dist+1});
            }

        }
    }

    arr[i][j] += k;
}
int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N >> K;
        int maximum = 0;
        ans = 0;
        vector<pair<int,int>> top;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
                maximum = max(maximum, arr[i][j]);
            }
        }

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                if(arr[i][j] == maximum)
                    top.push_back({i,j});
        
        for(int idx = 0; idx < top.size(); idx++){
            int x = top[idx].first;
            int y = top[idx].second;
            for(int k = 0; k <= K; k++){
                for(int i = 0; i < N; i++){
                    for(int j = 0; j < N; j++){
                        bfs(x,y,k,i,j);
                    }
                }
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}