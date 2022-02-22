#include <iostream>
#include <stack>
#include <vector>
#include <memory.h>
using namespace std;
//이 방법 제외하고도 vis배열 말고 추가로 done배열을 추가해 다음 노드가 이미 싸이클에 속했는지 확인 가능하다
int arr[100001];
bool vis[100001];
vector<int> ans;

int N, T;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int dfs(int x, int T){
    if(vis[x] == 1) return x;
    vis[x] = 1;
    int check = dfs(arr[x], arr[x]);
    if(T == check) ans.push_back(T);
    return check;
}

void dfs2(int x){
    if(vis[x] == 1) return;
    vis[x] = 1;
    N--;
    dfs2(arr[x]);
}

int main(){
    init();
    vector<int> cnt;
    cin >> T;
    while(T){
        cin >> N;
        ans.clear();
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= N; i++) cin >> arr[i];
        for(int i = 1; i <= N; i++){
            if(!vis[i]) dfs(i, i);
        }
        memset(vis, false, sizeof(vis));
        for(int k : ans) dfs2(k);
        cnt.push_back(N);
        T--;
    }
    for(int k : cnt) cout << k << endl;
    return 0;
}