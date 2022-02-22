#include <iostream>
#include <math.h>
using namespace std;

int N, M, K;
long long arr[1000001];
long long seg[4000004];

long long init_seg(int index, int start, int end){
    if(start == end) seg[index] = arr[start];
    else{
        int m = (start+end)/2;
        seg[index] = init_seg(index*2, start, m) + init_seg(index*2+1, m+1, end); 
    }
    return seg[index];
}

long long sum(int index, int start, int end, int left, int right){
    int m = (start+end)/2;

    if(end < left || start > right) return 0;
    else if(start >= left && end <= right) return seg[index];
    else return sum(index*2, start, m, left, right) + sum(index*2+1, m+1, end, left, right);


}

void update(int new_index, long long diff, int index, int start, int end){
    if(new_index < start || new_index > end) return;
    seg[index] += diff;
    if(start != end){
        int m = (start+end)/2;
        update(new_index, diff, index*2, start, m);
        update(new_index, diff, index*2+1, m+1, end);
    }
}

void init(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
}

int main(){
    init();
    cin >> N >> M >> K;
    int num_action = K + M;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    init_seg(1, 1, N);
    while(1){
        int action;
        if(num_action<=0) break;
        cin >> action;

        if(action == 1){
            int new_index;
            long long value;
            cin >> new_index >> value;
            long long diff = value-arr[new_index];
            update(new_index, diff, 1, 1, N);
            arr[new_index] = value;
        }
        else{
            int start, end;
            cin >> start >> end;
            cout << sum(1, 1, N, start ,end) << "\n";
        }

        num_action--;
    }
    return 0;

}

