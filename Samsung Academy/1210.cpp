#include <iostream>
#include <memory.h>
#define N 100

using namespace std;

int arr[101][101];
int vis[101][101];


bool search(int y){
    int x = 0;
    while(x < 100){
        if(arr[x][y] == 2) return true;
        vis[x][y] = 1;
        if(y+1 < 100 && arr[x][y+1] == 1 && !vis[x][y+1]){
            y++;
        }
        else if(y-1 >= 0 && arr[x][y-1] == 1 && !vis[x][y-1]){
            y--;
        }
        else x++;
    }
    return false;
}

int main(){
    int T = 10, t;
    while(T--){
        int ans = 0;
        char input;
        cin >> t;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> input;
                arr[i][j] = input - 48;
            }
        }

        for(int i = 0; i < N; i++){
            memset(vis, 0, sizeof(vis));
            if(arr[0][i] == 1 && search(i)){
                ans = i;
                break;
            }
        }

        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}