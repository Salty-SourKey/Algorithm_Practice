#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(){
    int T, N, caseNo = 1, temp;
    scanf("%d", &T);
    while(T--){
        vector<int> arr;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            scanf("%d", &temp);
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end(), compare);
        printf("Case %d: %d\n", caseNo++, arr.front());
    }
    return 0;
}