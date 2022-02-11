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
        cout << maxLength << endl;
    }    
    return 0;
}