#include <vector>
#include <iostream>

using namespace std;

vector<vector <int>> edge; //정점 i와 j번째 변과 연결된 정점
vector<vector <int>> dist; //정점 i의 j번째 변의 비용

int dijkstra(int from, int to, int v){
    int MAX = 1e9;
    int* d = new int[v]; //from부터의 거리를 저장하는 배열
    bool* check = new bool[v]; //정점이 탐색되었는지 확인하는 배열

    for(int i = 0; i < v; ++i){
        d[i] = MAX;
        check[i] = false;
    }
    d[from] = 0;
    //정점 개수 v만큼 반복
    for(int i = 0; i < v; ++i){
        //탐색하지 않은 정점 중 가장 가까운 정점을 now 추가한다
        int now = 0;
        int nowd = MAX;
        for(int j = 0; j < v; ++j){
            if(nowd > d[j] && !check[j]){
                now = j;
                nowd = d[j];
            }
        }
        if(nowd == MAX) break; //모든 정점을 다 조사했으면 break
        check[now] = true; //탐색한 정점은 탐색했다는 정보 기입

        for(int j = 0; j < edge[now].size(); ++j){
            int next = edge[now][j];
            int nextd = dist[now][j] + nowd;
            if(nextd < d[next]) d[next] = nextd;
        }

    return d[to];
    }
}