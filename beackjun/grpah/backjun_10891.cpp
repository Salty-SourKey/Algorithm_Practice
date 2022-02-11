#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
int dist[100001];
int cnt[100001];
int N, M;
int ans = 0;

int find_cycle(int k, int p){
    int c = 0;
    int f = 0;
    for(int i = 0; i < adj[k].size(); i++){
        int x = adj[k][i];
        if(p != x){
            if(dist[x] == 0){
                dist[x] = dist[k] + 1;
                c += find_cycle(x, k);
            }
            else if(dist[x] < dist[k]) c++;
            else if(dist[x] > dist[k]) f--;
        }
    }
    cnt[k] = c;
    if( cnt[k] >= 2) ans = 1;
    return c+f;
}

int main(){
    cin >> N >> M;
    int x, y;
    adj.resize(N+1);
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dist[1] = 1;
    find_cycle(1,0);
    
    printf("%s", ans ? "Not cactus" : "Cactus");
    return 0;
}
