#include <iostream>

int main(){
    int temp = 0x80000001;
    int check = 0x00000001;
    std::cout << ((temp ^ (~temp+1)) & (~temp+1));



    return 0;
}