#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dp[12][12];

class FloorBoards{
public:
    bool check(int x, int y){
        bool ans = 0;
        for(int i = 1; i <= y; ++i)
            for(int j = 1; j <= x; ++j)
                if(dp[i][j] == 0) return ans = 1;
        return ans;

    }
    int layout(vector<string> room){
        int ans = 0;
        int X = room[0].size();
        int Y = room.size();
        for(int i = 0; i <= X; ++i){
            dp[0][i] = 1;
            dp[i][0] = 1;
            dp[Y+1][i] = 1;
            dp[i][X+1] = 1;
        }
        for(int i = 0; i < Y; ++i){
            string temp = room[i];
            for(int j = 0; j < X; ++j){
                if(temp[j] == '#') dp[i+1][j+1] = 1;
            }
        }
       while(check(X,Y)){
            int x1, x2, y1, y2;
            int x_len, y_len;
            int check_1, check_2;
            int max_x, max_y, max_dir;
            int max_len = 0;
            for(int i = 1; i <= Y; ++i){
                for(int j = 1; j <= X; ++j){
                    if(dp[i][j] == 1) continue;
                    check_1 = 1;
                    check_2 = 1;
                    x_len = 1;
                    y_len = 1;
                    x1 = j;
                    x2 = j;
                    y1 = i;
                    y2 = i;
                    while(check_1 || check_2){
                        if(!check_1) ;
                        else if(dp[y1+1][x1] == 0 && dp[y1-1][x1] == 0){
                            check_1 = 0;
                            x_len = 1;
                        }
                        else if(dp[y1][x1+1] == 1 || (dp[y1+1][x1+1] == 0 && dp[y1-1][x1+1] == 0)) check_1 = 0;
                        else{
                            x_len++;
                            x1++;
                        }

                        if(!check_2) ;
                        else if(dp[y2][x2+1] == 0 && dp[y2][x2-1] == 0){
                            check_2 = 0;
                            y_len = 1;
                        }
                        else if(dp[y2+1][x2] == 1 || (dp[y2+1][x2+1] == 0 && dp[y2+1][x2-1] == 0)) check_2 = 0;
                        else{
                            y_len++;
                            y2++;
                        }
                    }
                    if(max_len <= x_len){
                        max_x = j;
                        max_y = i;
                        max_dir = 0;
                        max_len = x_len;
                    }
                    if(max_len <= y_len){
                        max_x = j;
                        max_y = i;
                        max_dir = 1;
                        max_len = y_len;
                    }
                }
            }       
            for(int i = 0; i < max_len; ++i){
                if(max_dir) dp[max_y+i][max_x] = 1;
                else dp[max_y][max_x+i] = 1;
            }
            ans++;       
        }   
        return ans;
    }
};

int main(){
    FloorBoards f;
    vector<string> room{".....", ".....", ".....", ".....", "....."};
    cout << f.layout(room);
    return 0;
}