#include <iostream>
using namespace std;

void swap(int* arr, int a, int b){
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

bool next_permutation(int* arr, int num){
    int i = num - 1;
    int j = num - 1;
    int k = num - 1;
    while(i > 0 && arr[i-1] >= arr[i])
        i--;
    while(arr[i-1] >= arr[j])
        j--;
    swap(arr, i-1, j);

    while(i < k)
        swap(arr, i++, k--);
    

    
}
int main(){
    int arr[10] = {3,2,1,4,11,10,8,3,2,1};
    next_permutation(arr, 10);
    for(int i = 0; i < 10; i++){
        cout << arr[i];
    }
    return 0;
}