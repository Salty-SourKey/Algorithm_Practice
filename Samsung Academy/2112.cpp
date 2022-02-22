//간단하 이진탐색 문제
//오차범위 고려를 "|현재 예측값 - 이전 예측값| < 오차범위"로 계산함

#include <iostream>
#include <math.h>

using namespace std;

int D, W, K, ans;
int arr[13][20];

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

void input(){
    for(int i = 0; i < D; i++)
        for(int j = 0; j < W; j++)
            cin >> arr[i][j];
}

bool check(){
    for(int j = 0; j < W; j++){
        int cnt = 1;
        int cur = arr[0][j];
        for(int i = 1; i < D; i++){
            if(cur == arr[i][j]){
                cnt += 1;
                if(cnt == K)
                    break;
            }
            else{
                cnt = 1;
                cur = arr[i][j];
            }
        }
        if(cnt != K) return false;
    }
    return true;
}

void dfs(int num, int idx){
    if(num >= ans || num > K) return;

    if(check()){
        if(num < ans)
            ans = num;
        return;
    
    }

    if(idx == D) return;

    int temp[20];
    int cnt;   
    cnt = 0;

    dfs(num, idx+1);

    for(int i = 0; i < W; i++){
        temp[i] = arr[idx][i];
        arr[idx][i] = 1;    
    }
    
    dfs(num+1, idx+1);
    
    for(int i = 0; i < W; i++)
        arr[idx][i] = 0;
    
    dfs(num+1, idx+1);
    
    for(int i = 0; i < W; i++)
        arr[idx][i] = temp[i];

}

int main(){
    int T;
    init();
    cin >> T;
    for(int  t = 1; t <= T; t++){
        cin >> D >> W >> K;
        ans = D;
        input();
        if(K == 1)
            ans = 0;
        else
            dfs(0,0);
        

        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}