//조합 + DFS

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int arr[7];
int sorted[7];
int maximum;

bool compare(int a, int b){
    return b < a;
}
void swap(int* arr, int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int power(int v, int n){
    int k = 1;
    while(n--){
        k *= v;
    }
    return k;
}

bool hasCommon(int arr[], int n){
    map<int, int> dict;
    for(int i = 0; i < n; i++){
        if(dict[arr[i]]) return true;
        dict[arr[i]]++;
    }
    return false;
}

void find_combination(int arr[], int n, int k){
    map<int, vector<int>> dict;
    int value = 0;
    int idx = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] == sorted[j]) idx++;
        else break;
    }
    
    if(k == 0){
        for(int i = 0; i < n; i++)
            value += arr[i] * power(10, n-i-1);
        maximum = (maximum < value) ? value : maximum;
        return;
    }
    else if(idx == n){
        if(k % 2 == 0 || hasCommon(arr, n)){
            for(int i = 0; i < n; i++)
                value += arr[i] * power(10, n-i-1);
            maximum = (maximum < value) ? value : maximum;
            return;
        }
        else{
            swap(arr, n-2, n-1);
            for(int i = 0; i < n; i++)
                value += arr[i] * power(10, n-i-1);
            maximum = (maximum < value) ? value : maximum;
            return;
        }
    }
    else{    
        for(int i = idx; i < n; i++)
            dict[arr[i]].push_back(i);
        map<int, vector<int>>:: iterator iter = dict.end();
        iter--;
            
        for(int i = 0; i < iter->second.size(); i++){
            swap(arr, idx, iter->second[i]);
            find_combination(arr, n, k-1);
            swap(arr, idx, iter->second[i]);
        }
    }
}


int main(){
    int C;
    cin >> C;
    for(int i = 1; i <= C; i++){
        maximum = 0;
        string number;
        int k, n, idx = 0;
        cin >> number >> k;
        n = number.length();
        for(int j = 0; j < number.length(); j++){
            sorted[j] = (number[j]-48);
            arr[j] = (number[j] - 48);
        }
        sort(sorted, sorted+n, compare);
        

        find_combination(arr, n, k);
        cout << "#" << i << " " << maximum << endl;
    }
    return 0;
}