#include <stdio.h>
int r[1001];
int rectangle(int x){
    if(x==1) return 1;
    if(x==2) return 2;
    if(r[x] != 0) return r[x];
    return r[x] = (rectangle(x-1) + rectangle(x-2))%10007; //주석 참고
}
int main(){
    int n,k;
    scanf("%d",&n);
    k = rectangle(n);
    printf("%d", k);
    return 0;
}
/* A = aC + A%C
   B = bC + B%C
   A + B = (a+b)C + A%C + B%C  여기서 양변에 %c하면 (a+b)C는 C의 배수이기 때문에
   (A + B)%C = (A%C + B%C)%C ==> 
*/