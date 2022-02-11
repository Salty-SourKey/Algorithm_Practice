#include <iostream>

using namespace std;

char cell[3][3];

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

int main(){
    int N, ans;
    bool flag;
    cin >> N;
    while(N--){
        ans = 0;
        flag = true;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                cin >> cell[i][j];
        
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(cell[i][j]-48) flag = false;

        if(flag) cout << -1 << endl;
        else{
            while(1){

                char temp[3][3] = {0,};
                flag = true;
                
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        for(int k = 0; k < 4; k++){
                            if(i+x[k] >= 0 && i+x[k] < 3 && j+y[k] >= 0 && j+y[k] < 3){
                                temp[i][j] += cell[i+x[k]][j+y[k]];
                                temp[i][j] -= 48;    
                            }
                        }
                        temp[i][j]%=2;
                    }
                }
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        if(temp[i][j]) flag = false;
                        cell[i][j] = temp[i][j];
                    }
                }

                if(flag){
                    cout << ans << endl;
                    break;
                }
                ans++;
            }
        }
            

        
    }
    return 0;
}