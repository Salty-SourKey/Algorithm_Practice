#include <iostream>
#include <algorithm>
using namespace std;
int score[3];
bool isRed[201];
class ColorfulBoxesAndBalls{
public:
    int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors){
        int ans = 0;
        for(int i = 0; i < numRed; ++i) isRed[i] = true;
        score[0] = onlyRed;
        score[1] = onlyBlue;
        score[2] = bothColors;
        ans = dfs(numRed, numBlue, 0);
    }
    int dfs(int RedBall, int BlueBall, int n){
        if(isRed[n] == true){
            if(RedBall == 0 && BlueBall == 0) return 0;
            if(RedBall == 0 && BlueBall != 0) return dfs(RedBall, BlueBall-1, n+1)+score[2];
            if(BlueBall == 0 && RedBall != 0) return dfs(RedBall-1, BlueBall, n+1)+score[0];
            return max(dfs(RedBall-1, BlueBall, n+1)+score[0], dfs(RedBall, BlueBall-1, n+1)+score[2]);
        }
        else{
            if(RedBall == 0 && BlueBall == 0) return 0;
            if(RedBall == 0 && BlueBall != 0) return dfs(RedBall, BlueBall-1, n+1)+score[1];
            if(BlueBall == 0 && RedBall != 0) return dfs(RedBall-1, BlueBall, n+1)+score[2];
            return max(dfs(RedBall-1, BlueBall, n+1)+score[2], dfs(RedBall, BlueBall-1, n+1)+score[1]);
        }
    }
};
int main(){
    int numRed = 100;
    int numBlue = 100;
    int onlyRed = 100;
    int onlyBlue = 400;
    int bothColors = 200;
    ColorfulBoxesAndBalls calc;
    cout << calc.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
    return 0;
}
