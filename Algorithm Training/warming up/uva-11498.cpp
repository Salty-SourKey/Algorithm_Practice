#include <cstdio>

using namespace std;

int main(){
    int K, N, M, X, Y;

    while(scanf("%d", &K), K){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < K; i++){
            scanf("%d %d", &X, &Y);
            X -= N;
            Y -= M;

            if(!(X && Y)) printf("divisa\n");
            else if(X > 0 && Y > 0) printf("NE\n");
            else if(X > 0 && Y < 0) printf("SE\n");
            else if(X < 0 && Y > 0) printf("NO\n");
            else printf("SO\n");
        }
    }
    return 0;
}
