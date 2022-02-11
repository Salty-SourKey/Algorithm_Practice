#include <iostream>
using namespace std;

char arr[] = {'A', 'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void print_arr(){
    for(int i = 0; i < 27; i++) cout << arr[i];
    cout << endl;
}
void swap(char* a, char* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int depth, int n){
    if(depth == n) print_arr();

    for(int i = depth; i < n; i++){
        swap(&arr[i], &arr[depth]);
        permutation(depth+1, n);
        swap(&arr[i], &arr[depth]);
    }
}
int main(){
    permutation(0, 26);
    return 0;
}
