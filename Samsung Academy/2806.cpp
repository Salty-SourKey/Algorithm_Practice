#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
//배열 안의 1 => 놓을 수 있는 자리
//배열 안의 0 => 놓을 수 없는 자리
//한 row 씩 놓을 수 있는 자리를 확인


int answer, N;
void init(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
void check_validity(int x, int y, int chess[][15]){
    if(x == N-1){
        answer++;
        return;
    }

    int possible[15][15];
    copy(&chess[0][0], &chess[0][0]+225, &possible[0][0]);
    //x, y에 퀸을 놓았을 때 놓을 수 없는 칸 업데이트
    for(int i = x+1; i < N; i++){
        for(int j = 0; j < N; j++)
            if(possible[i][j] && (y == j || abs(x-i)-abs(y-j) == 0))
                possible[i][j] = 0;    
    }
    //다음 row에 놓을 수 있는 곳 Search
    for(int i = 0; i < N; i++)
        if(possible[x+1][i]) check_validity(x+1, i, possible);
}

int main(){
    int T;
    init();
    cin >> T;
    for(int t = 1; t <= T; t++){
        answer = 0;
        int chess[15][15];
        cin >> N;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                chess[i][j] = 1;
        for(int i = 0; i < N; i++)
            check_validity(0, i, chess);
        cout << "#" << t << " " << answer << endl;
    }
    return 0;    
}