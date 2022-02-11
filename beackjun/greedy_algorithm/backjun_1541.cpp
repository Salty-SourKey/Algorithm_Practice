#include <iostream>
#include <string>
using namespace std;
string a;
int main(){
    int min = 0;
    string temp = "";
    bool minus = false;
    cin >> a;
    for(int i = 0; i < a.size()+1; i++){                          // 마지막 temp가 계산이 안되서 한번 더 반복
        if(a[i] == '+' || a[i] == '-' || a[i] == '\0'){           // 만약 a[i]가 기호 또는 널 문자일 경우
            if(minus) min-=stoi(temp);                            // temp값을 최솟값에서 빼줌 -> 마이너스가 나온 순간부터는 괄호를 적절히 취해 모든 숫자를 다 뺄 수 있기 때문이다
            else min+=stoi(temp);                                 // 마이너스가 아직 나오지 않았을때까지는 더해준다
            if(a[i] == '-') minus = true;                         // 마이너스가 나온 순간 불값을 변경!
        temp = "";                                                // temp값 초기화
        }
        else temp+=a[i];                                          // 부호 나올때까지는 숫자이기 때문에 temp값에 받아준다
    }
    cout << min;
    return 0;
}