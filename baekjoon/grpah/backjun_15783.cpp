#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//Parent를 찾는 문제!!! => Parent가 없다면 Cycle이니 Parent Node개수 + Cycle개수 찾으라
//잘못된 풀이 83%에서 막힘
//DFS와 Stack의 조합을 사용해 Cycle의 개수 구할 수 있음!
//DFS를 통해 stack에 집어넣은 후 pop하면서 다시 DFS를 돌려라

int N, M, count;
int arr[100001];
bool vis[100001];
vector<vector<int>> vec(100001);

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void bfs(int x){
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    while(!q.empty()){
        int k = q.front();
        vis[k] = 1;
        q.pop();
        for(int i = 0; i < vec[k].size(); i++)
            if(!vis[vec[k][i]]) q.push(vec[k][i]);        
    }
}

void bfs2(int x){
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    while(!q.empty()){
        int k = q.front();
        vis[k] = 1;
        q.pop();
        for(int i = 0; i < vec[k].size(); i++)
            if(!vis[vec[k][i]]) q.push(vec[k][i]);
        if(!vis[arr[k]]) q.push(arr[k]);
    }
    count++;
}

int main(){
    init();
    cin >> N >> M;
    int x, y;
    for(int i = 0; i < N; i++) arr[i] = -1;
    for(int i = 0; i < M; i++){
        cin >> x >> y;
        arr[y] = x;
        vec[x].push_back(y);
    }
    for(int i = 0; i < N; i++){
        if(arr[i] == -1){
            bfs(i);
            count++;
        }
    }
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            bfs2(i);
        }
    }
    cout << count;

    return 0;
}
/*
#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

int n, m,cnt;
bool visit[100001];
vector<vector<int>> adj;
stack<int> st;

void dfs(int v,bool t) {
	if (visit[v]) return;
	visit[v] = true;
	for (int i : adj[v]) {
		dfs(i,t);
	}
	if(t) st.push(v);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	adj.resize(n);

	for (int i = 0; i < m; i++) {
		int q, w;
		cin >> q >> w;
		adj[q].push_back(w);
	}
	for (int i = 0; i < n; i++) {
		dfs(i,true);
	}
	memset(visit, false, sizeof(visit));
	while (!st.empty()) {
		int cur = st.top();
		st.pop();
		if (visit[cur]) continue;
		cnt++;
		dfs(cur,false);
	}
	cout << cnt << '\n';
	return 0;
}

*/