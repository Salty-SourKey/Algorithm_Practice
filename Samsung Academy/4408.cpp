//겹치는것 없이 다 배치할 때 걸리는 최소 횟수
//== 최대로 많이 겹친 구간의 겹친 횟수 
#include <iostream>
#include <math.h>
#include <memory.h>
int room[201];

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N, ans = 0;
        cin >> N;
        memset(room, 0, sizeof(room));
        for(int i = 0; i < N; i++){
            int from;
            int to;
            cin >> from >> to;
            if(from > to){
                int temp = to;
                to = from;
                from = temp;
            }
            if(from % 2 == 0) from /= 2;
            else from = from / 2 + 1;

            if(to % 2 == 0) to /= 2;
            else to = to / 2 + 1;

            for(int k = from; k <= to; k++)
                room[k]++;
        }
        for(int i = 1; i <= 200; i++)
            ans = max(ans, room[i]);

        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}