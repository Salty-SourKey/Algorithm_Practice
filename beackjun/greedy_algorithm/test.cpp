#include "iostream"
#define CIRCLE(X) 3.14 * (x) * (x)
#undef CIRCLE

int main(){
    int x= CIRCLE(4);
    float f[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    
    printf("%f", *(f+5));
    
    return 0;
}

int func( float a, int b, long c){
    return b*c;
}