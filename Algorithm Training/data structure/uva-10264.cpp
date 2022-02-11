#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<unsigned int> arr;


//이웃한 corner라는 것은 bit 하나만 차이나는 corner를 뜻한다
//bit 하나만 차이날때의 특징을 찾는것보다 하나만 차이나는 corner를 그냥 구하는 것이 훨씬 빠르다
//이웃하는 corner는 개수가 정해저있기 때문이다.

unsigned int potency(unsigned int idx, unsigned int dim){
    unsigned int iter = 1;
    unsigned int sum = 0;

    for(int i = 0; i < dim; i++){
        sum += arr[idx ^ iter];
        iter = iter << 1;
    }
    return sum;
}

int main(){
    unsigned int weight, N, ans, pot, temp, iter;    
    while(cin >> N){
        ans = 0;
        for(int i = 0; i < (1 << N); i++){
            cin >> weight;
            arr.push_back(weight);
        }
        for(unsigned int i = 0; i < (1 << N); i++){
            pot = potency(i, N);
            iter = 1;
            for(int j = 0; j < N; j++){
                temp = potency(i ^ iter, N);
                iter = iter << 1;
                ans = max(ans, pot+temp);                
            } 
        }
        cout << ans << endl;
        arr.clear();
    }
    return 0;
}