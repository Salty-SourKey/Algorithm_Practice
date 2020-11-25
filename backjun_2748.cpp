#include<stdio.h>
int main(){
    int n;
    long long int a = 1, b = 1, c = 0;
    scanf("%d",&n);
    if(n == 1) c = 1;
    if(n == 2) c = 1;
    for(int i = n; i > 2; --i){
        c = a + b;
        a = b;
        b = c;
    }
    printf("%lld", c);
    return 0;
}