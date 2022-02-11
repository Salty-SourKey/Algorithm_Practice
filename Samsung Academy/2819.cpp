#include <iostream>
#include <string>
#include <map>

#define LEN 4

using namespace std;

char arr[LEN][LEN];
int x_dir[4] = {1,-1,0,0};
int y_dir[4] = {0,0,1,-1};

map<string, int> dict;
int ans;

void count(string num, int x, int y, int n){
    num += arr[x][y];
    n++;
    if(n == 7){
        if(!dict[num]){
            ans++;
            dict[num]++;
        }
        return;
    }
    for(int i = 0; i < LEN; i++){
        if(x+x_dir[i] < 0 || x+x_dir[i] >= LEN || y+y_dir[i] < 0 || y+y_dir[i] >= LEN)
            continue;
        else
            count(num, x+x_dir[i], y+y_dir[i], n);
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        ans = 0;
        for(int i = 0; i < LEN; i++)
            for(int j = 0; j < LEN; j++)
                cin >> arr[i][j];
                
        for(int i = 0; i < LEN; i++)
            for(int j = 0; j < LEN; j++)
                count("", i, j, 0);
        dict.clear();
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}