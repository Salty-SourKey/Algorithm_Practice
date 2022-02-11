//순회 최단 거리를 구하는 tsp 문제 -> 완전 탐색으로 해결
//DP[방문한 도시 상태][현재 도시 위치]로도 해결 가능하단다


#include <iostream>
#include <algorithm>
#include <math.h>
#include <Vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N, com_x, com_y, cus_x, cus_y, home_x, home_y, sum, ans = 1000000000;
        int combination[11] = {0,1,2,3,4,5,6,7,8,9,10};
        vector<pair<int,int>> coor;
        cin >> N >> com_x >> com_y  >> home_x >> home_y;

        for(int i = 0; i < N; i++){
            cin >> cus_x >> cus_y;
            coor.push_back({cus_x, cus_y});
        }

        do{
            int cur_x = com_x;
            int cur_y = com_y;

            sum = 0;
            for(int i = 0; i < N; i++){
                sum += (abs(cur_x-coor[combination[i]].first) + abs(cur_y-coor[combination[i]].second));
                cur_x = coor[combination[i]].first;
                cur_y = coor[combination[i]].second;
            }
            sum += (abs(cur_x-home_x) + abs(cur_y-home_y));
            ans = min(ans, sum);
        } while(next_permutation(combination, combination+N));
        

        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}