//중복되지 않는 Sequence의 최대 길이를 구하라
//Greedy + Map 활용
//입력 하나 받을 때 마다 중복된게 있는지 확인
//없다면 지금까지의 Length + 1, 해당 입력의 마지막 등장 위치 초기화 => 지금까지의 maxLength와 비교
//있다면 지금까지 나온 중복된 것 중 가장 나중에 나온 위치 확인, 입력받은 곳 까지의 중복 없는 길이 구함 => maxLength와 비교


#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> dict;

int main(){
    int caseNum, N, n;
    cin >> caseNum;
    while(caseNum--){

        int maxLength = 0;
        int curLength = 0;
        int lastDuplicate = 0;
        int last;

        cin >> N;
        for(int i = 1; i <= N; i++){
            cin >> n;
            last = dict[n];
            if(last){
                lastDuplicate = max(lastDuplicate, last);
                curLength = i - lastDuplicate - 1;
            }
            curLength++;
            dict[n] = i;
            maxLength = max(maxLength, curLength);
        }
        dict.clear();
        cout << maxLength << endl;
    }    
    return 0;
}