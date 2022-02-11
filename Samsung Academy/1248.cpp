#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

vector<vector<int>> tree(10001);

int level[10001];
int parent[10001];

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void set_info(int cur, int from, int lv){
    parent[cur] = from;
    level[cur] = lv;
    for(int i = 0; i < tree[cur].size(); i++){
        if(tree[cur][i] != from)
            set_info(tree[cur][i], cur, lv+1);
    }
}

int cnt(int x){
    int ans = 1;
    for(int i = 0; i < tree[x].size(); i++){
        if(tree[x][i] != parent[x]){
            ans += cnt(tree[x][i]); 
        }
    }
    return ans;
}

int main(){
    init();
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int V, E, x, y, input_x, input_y;
        for(int i = 0; i < tree.size(); i++)
            tree[i].clear();

        cin >> V >> E >> x >> y;
        for(int i = 0; i < E; i++){
            cin >> input_x >> input_y;
            tree[input_x].push_back(input_y);
            tree[input_y].push_back(input_x);
        }
        
        parent[1]= 1;
        level[1] = 0;
        for(int i = 0; i < tree[1].size(); i++)
            set_info(tree[1][i], 1, 1);
       
        if(level[x] > level[y]){
            int temp = x;
            x = y;
            y = temp;
        }
        
        int temp = y;
        for(int i = 0; i < level[y]-level[x]; i++){
            temp = parent[temp];
        }
        y = temp;    
        
        while(x != y){
            x = parent[x];
            y = parent[y];
        }
        cout << "#" << t << " " << x << " " << cnt(x) << endl; 
    }
    return 0;
}