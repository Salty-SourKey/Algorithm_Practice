#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> edge; //정점 i의 j번째 변의 목적지
vector<vector<int>> dist; //정점 i의 j번째 변의 비용

int spfa(int from, int to, int v){
    int MAX = (int)1e9;
    int* d = new int[v]; //from부터의 거리를 저장하는 배열
    bool* inQueue = new bool[v]; //큐에 들어 있는 정점을 저장하는 배열 
    for(int i = 0; i < v; ++i){
        d[i] = MAX;
        inQueue[i] = false;
    }
    d[from] = 0;
    inQueue[from] = true;
    queue<int> q;
    q.push(from);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        inQueue[now] = false;
        for(int i = 0; i < edge[now].size(); ++i){
            int next = edge[now][i];
            int nextd = d[now] + dist[now][i];
            if(nextd < d[next]){ //더 나은 조건의 답을 찾을 시 d[next] 업데이트
                d[next] = nextd;
                if(!inQueue[next]){ //큐에 들어있지 않은 경우만 추가한다
                    inQueue[next] = true;
                    q.push(next);
                }
            }
        }
    }
    return d[to];
}