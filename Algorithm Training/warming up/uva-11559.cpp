#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, B, H, W, minimum;
    while(cin >> N >> B >> H >> W){
        minimum = B+1;
        for(int i = 0; i < H; i++){
            int price, available;
            scanf("%d", &price);
            for(int j = 0; j < W; j++){
                scanf("%d", &available);
                if(available >= N && price*N <= B)
                    minimum = min(minimum, price*N);
            
            }
        }
        if(minimum == B+1) printf("stay home\n");
        else printf("%d\n", minimum);
    }
    return 0;
}