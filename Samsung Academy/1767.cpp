//완전탐색 문제인데 생각보다 시간 많이걸림
//1. 상하좌우만 탐색하는게 아닌 아예 코어와 연결 안한다는 선택지도 고려해야 함
//2. 그럼 코어 하나 당 5개 방향을 탐색해야하는데 그러면 시간초과 남
//3. 최대 연결 코어 개수가 전체 코어 개수와 동일하다면 최대 연결 코어 개수는 불변!
// => 즉, 연결 안한다는 선택지는 무시 가능 


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<pair<int,int>> pos;
int arr[13][13];
int N;
int ans = 1000;;
int MAX_CORE;

void func(int idx, int prev, int cur_core){
    if(idx == pos.size()){
        if(MAX_CORE < cur_core){
            MAX_CORE = cur_core;    
            ans = prev;
        }
        else if(MAX_CORE == cur_core)
            ans = min(prev, ans);
        return;
    }
    int x = pos[idx].first;
    int y = pos[idx].second;
    for(int i = 0; i < 5; i++){
        int cnt = 0;
        bool check = true;
        if(i == 0){
            for(int j = 0; j < y; j++){
                if(arr[x][j]){
                    check = false;
                    break;
                }
                else{
                    cnt++;
                    arr[x][j] = 2;
                }
            }

            if(check)
                func(idx+1, prev + cnt, cur_core+1);

            for(int j = 0; j < y; j++){
                if(arr[x][j] == 1)
                    break;
                else if(cnt){
                    cnt--;
                    arr[x][j] = 0;
                }
            }
        }
        else if(i == 1){
            for(int j = 0; j < x; j++){
                if(arr[j][y]){
                    check = false;
                    break;
                }
                else{
                    cnt++;
                    arr[j][y] = 2;
                }
            }

            if(check)
                func(idx+1, prev+cnt, cur_core+1);

            for(int j = 0; j < x; j++){
                if(arr[j][y] == 1)
                    break;
                else if(cnt){
                    cnt--;
                    arr[j][y] = 0;
                }
            }
        }
        else if(i == 2){
            for(int j = N-1; j > y; j--){
                if(arr[x][j]){
                    check = false;
                    break;
                }
                else{
                    cnt++;
                    arr[x][j] = 2;
                }
            }

            if(check)
                func(idx+1, prev+cnt, cur_core+1);

            for(int j = N-1; j > y; j--){
                if(arr[x][j] == 1)
                    break;
                else if(cnt){
                    cnt--; 
                    arr[x][j] = 0;
                }
            }
        }
        else if(i == 3){
            for(int j = N-1; j > x; j--){
                if(arr[j][y]){
                    check = false;
                    break;
                }
                else{
                    cnt++;
                    arr[j][y] = 2;
                }
            }

            if(check)
               func(idx+1, prev+cnt, cur_core+1);

            for(int j = N-1; j > x; j--){
                if(arr[j][y] == 1)
                    break;
                else if(cnt){
                    cnt--;
                    arr[j][y] = 0;
                }
            }
        }
        else if(i == 4 && MAX_CORE != pos.size())
            func(idx+1, prev, cur_core);
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N;
        pos.clear();
        MAX_CORE = 0;
        ans = 1000;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
                if(arr[i][j] == 1){
                    pos.push_back({i,j});
                }
            }
        }
        func(0,0,0);

        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}