#include <iostream>
#include <math.h>
#define PI 3.141592
using namespace std;

int x_1 = 0;
int y_1 = 50;

float calc_angle(int x_2, int y_2){
    int dot = x_1*x_2 + y_1*y_2;
    int det = x_1*y_2 -y_1*x_2;

    float angle = atan2(det, dot) * 180 / PI;

    if(angle < 0 ) return -angle;
    else return 360 - angle;
    
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int x_2, y_2, ans;
        float P, target;
        cin >> P >> x_2 >> y_2;

        x_2 -= 50;
        y_2 -= 50;

        target = (P/100) * 360;

        if(x_2*x_2 + y_2*y_2 > 2500) ans = 0;
        else if(target >= calc_angle(x_2, y_2)) ans = 1;
        else ans = 0;     

        cout << "#" << t << " " << ans << endl;
    }

}