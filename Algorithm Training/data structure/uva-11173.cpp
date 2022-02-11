#include <iostream>
#include <math.h>
#define ll long long 

using namespace std;


ll grey(ll idx){
    ll k = 2;
    if(idx == 0) return 0;
    if(idx == 1) return 1;
    while(1){
        if(((1 << k)-1)-idx >= 0)
            break;
        k++;
    }

    return (1 << (k-1))+grey((1 << k)-1-idx);
}

int main(){
    int N;
    ll k, idx;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> k >> idx;
        cout << grey(idx) << endl;
    }
    return 0;
}