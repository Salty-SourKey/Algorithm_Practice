#include <cstdio>

using namespace std;

int main(){
    int H, ans;
    double F, U, D, height;
    while(scanf("%d %lf %lf %lf", &H, &U, &D, &F), H){
        ans = 1;
        F = U * (F / 100.0);
        height = U;
        while(1){
            if(height <= 0){
                printf("failure on day %d\n", ans); 
                break;
            }
            if(ans > 1)
                height += U;
                
            if(height > H){
                printf("success on day %d\n", ans);
                break;
            }
            U -= F;
            if(U <= 0) U = 0;
            height -= D;
            if(height < 0){
                printf("failure on day %d\n", ans); 
                break;
            }
            ans++;
        }
    }
    return 0;
}