#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> arr;
    int T, temp;
    int caseNo = 1;
    scanf("%d", &T);
    while(T--){
        for(int i = 0; i < 3; i++){
            scanf("%d", &temp);
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        printf("Case %d: %d\n", caseNo++, arr.at(1));
        arr.clear();
    }

}