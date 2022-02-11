//홀수만 더하기
#include <iostream>
using namespace std;
int main(){
    int T, n, N = 1;
    cin >> T;
    while(T--){
        int ans = 0;
        for(int i = 0; i < 10; i++){
            cin >> n;
            if(n % 2 == 1) ans += n;
        }
        cout << "#" << N++ << " " << ans << endl;
    }
    return 0;
}