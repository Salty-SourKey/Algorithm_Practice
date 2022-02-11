#include <iostream>

using namespace std;

int main(){
    int N, n;
    bool flag;
    while(cin >> N >> n){
        if(N == 0 && n == 0) break;
        
        char big[500][500] = {0,};
        char small[500][500] = {0,};
        char temp[500][500] = {0,};
        int ans[4] = {0,};

        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> big[i][j];
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> small[i][j];

        for(int k = 0; k < 4; k++){
            //find
            for(int i = 0; i < N-n+1; i++){
                for(int j = 0; j < N-n+1; j++){
                    flag = true;
                    for(int l = 0; l < n; l++){
                        for(int m = 0; m < n; m++){
                            if(big[i+l][j+m] != small[l][m]) flag = false;        
                        }
                    }
                    if(flag) ans[k]++; 
                }
            }
            //rotate
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    temp[j][n-i-1] = small[i][j];
                
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    small[i][j] = temp[i][j];
        }

        for(int i = 0; i < 4; i++){
            if(i) cout << " " << ans[i];
            else cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}