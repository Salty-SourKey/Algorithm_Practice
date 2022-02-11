#include <iostream>
#include <bitset>
#include <stdlib.h>

using namespace std;

int main(){
    int N, temp1, temp2, diff;
    bool check;                             //모든걸 다 계산하면서 flag를 업데이트 하는게 아닌 결과에 따라 한번만 업데이트 하자
    bitset<3000> bs;
    while(cin >> N){
        bs.reset();                         //초기화 안해서 문제 생겼음
        check = false;
        cin >> temp1;
        for(int i = 1; i < N; i++){
            cin >> temp2;
            diff = abs(temp2-temp1);
            if(diff < 3000)                 //예외처리를 안해서 문제 생겼음
                bs[diff] = 1;
            temp1 = temp2;
        }

        for(int i = 1; i < N; i++)
            if(bs[i] == 0) check = true;

        if(check) cout << "Not jolly" << endl;
        else cout << "Jolly" << endl;

    }
    return 0;
}