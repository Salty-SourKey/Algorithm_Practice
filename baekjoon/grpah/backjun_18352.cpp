#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1000001
using namespace std;


int N, M, K, X;
int dist[300001];
vector<vector<int>> graph(300001);


void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void bfs(){
    queue<int> next;
    vector<int> answer;

    for(int i = 1; i <= N; i++) dist[i] = INF;
    dist[X] = 0;
    next.push(X);
    while(!next.empty()){
        int k = next.front();
        if(dist[k] > K) break;

        next.pop();
        for(int i = 0; i < graph[k].size(); i++){
            if(dist[k] + 1 < dist[graph.at(k).at(i)]){
                dist[graph.at(k).at(i)] = dist[k] + 1;   
                next.push(graph.at(k).at(i));
            }
        }
    }
    for(int i = 1; i <= N; i++)
        if(dist[i] == K) answer.push_back(i);

    if(answer.empty()) cout << -1;
    else{
        for(int i = 0; i < answer.size(); i++)
            cout << answer[i] << endl;
        
    }
}

int main(){
    init();
    int index, temp;
    cin >> N >> M >> K >> X;
    for(int i = 0 ; i < M; i++){
        cin >> index >> temp;
        graph[index].push_back(temp);
    }
    bfs();

    return 0;
}
//만약 height가 k만큼 내려간 곳을 확인하여 풀려면
//while(!queue.empty){
//  int qsize = queue.size();
//  while(qsize--){} 이렇게 하면 한 height씩 구할 수 있음