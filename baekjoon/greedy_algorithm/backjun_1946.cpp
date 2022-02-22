#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
typedef struct{
    int score_a;
    int score_b;
} Score;       //점수 두 개 가진 구조체 생성, pair<int,int>로도 가능할듯 

Score s[100000];
bool check_a(Score a, Score b){return a.score_a < b.score_a;} //구조체의 정렬을 위한 조건문

int main()
{
    ios::sync_with_stdio(false);
    int t,n,count,min;
    cin >> t;
    while(t--){
        count = 0;
        min = 100001;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> s[i].score_a >> s[i].score_b;  //한 쪽의 등수들을 정렬시키면 합격하기 위해선
        sort(s, s+n);                                                    //무조건 정렬된 등수의 하위권들은 자기보다 상위권들의
        for(int i = 0; i < n; i++){                                      //정렬 안된 등수보다 높아야 한다
            if(s[i].score_b < min){                                      //따라서 반복문을 돌면서 최솟값을 계속 갱신하면서
                count++;                                                 //등수의 최솟값을 갱신하면 count++
                min = s[i].score_b;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}