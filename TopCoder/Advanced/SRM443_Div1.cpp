#include <iostream>
#include <algorithm>
using namespace std;


class BinaryFlips{
public:
    int minimalMoves(int A, int B, int K){
        int rest, use;
        for(int i = 0; i <= A+B; ++i){
            rest = i * K - A;
            use = (((i-1)/2)*A + (i/2)*B)*2;
            if(rest >= 0 && rest % 2 == 0 && rest <= use) return i;
        }
    return -1;
    }
};

int main(){
    int A = 4;
    int B = 0;
    int K = 3;
    BinaryFlips b;
    cout << b.minimalMoves(A,B,K);
    return 0;
}