#include <iostream>
using namespace std;
int main()
{
    int n ,m, max;
    cin >> n >> m;
    if(n == 1) max = 1;                     //이 문제는 특정 구간에서 갖는 특징들이 있다
    else if(n == 2){                        //세로 길이가 3보다 클 경우 전혀 신경을 쓸 필요가 없다. 
        if(m >= 7) max = 4;                 //어차피 최대값은 위로 두칸 갔다 아래 두칸 가는거나 위로 두칸을 두번 가는거나
        else max = (m-1)/2 + 1;             //움직이는 횟수는 같다. 따라서 높이가 1일 때와 2일 때의 경우를 구하고
    }                                       //나버지 else문에서 가로 길이에 따른 최댓값을 구했다
    else{
        if(m < 4) max = m;
        else if(4 <= m && m < 7) max = 4;
        else max = m - 2;
    }
    cout << max;
    return 0;
}