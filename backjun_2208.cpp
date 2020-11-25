#include <stdio.h>
#include <algorithm>
using namespace std;
int array[100000];
int pSum[100001];
int main(){
    int N,M,result=0;
    scanf("%d %d\n", &N, &M);
    for(int i = 0; i < N; ++i){
        scanf("%d", &array[i]);
        pSum[i+1] = pSum[i] + array[i];
    }
    int minimum=0;
    for(int i = M-1; i< N; i++){
        minimum = min(minimum, pSum[i+1-M]);
        result = max(pSum[i+1]-minimum, result);
    }
    printf("%d\n", result);
    return 0;
}