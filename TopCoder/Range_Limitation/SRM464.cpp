#include <iostream>
#include <algorithm>
using namespace std;

class ColorfulBoxesAndBalls{
public:
    int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors){
        int ans = -200001;
        if(numBlue >= numRed)
            for(int i = 0 ; i <= numRed; ++i) ans = max(ans, (numRed-i)*onlyRed + (numBlue-i)*onlyBlue + i * 2* bothColors);
        else
            for(int i = 0 ; i <= numBlue; ++i) ans = max(ans, (numBlue-i)*onlyBlue + (numRed-i)*onlyRed + i * 2 * bothColors);
        return ans;
    }
};

int main(){
    int numRed = 1;
    int numBlue = 4;
    int onlyRed = 20;
    int onlyBlue = -30;
    int bothColors = -10;
    ColorfulBoxesAndBalls calc;
    cout << calc.getMaximum(numRed, numBlue, onlyRed, onlyBlue, bothColors);
    return 0;
}