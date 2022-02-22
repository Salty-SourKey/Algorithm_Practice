//재귀함수의 깊이가 20000 넘어가니 segmentation fault가 남.. 주의!
//최소 공배수, 최대 공약수 구하는 알고리즘 알게됨

#include <iostream>

using namespace std;

int ans, N;
long long arr[100001];


void input(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];
}

long long gcd(long long a, long long b){
    int  c;
    while(b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

void solve(){
    long long cd = arr[0];
    long long temp;
    for(int i = 1; i < N; i++){
        cd = gcd(cd, arr[i]);
        if(cd == 1) 
            break;
    }
    ans = cd;    

    for(int i = 0; i < N; i++){
        temp = arr[i];
        arr[i] = arr[(i+1) % N];
        cd = arr[0];
        for(int j = 1; j < N; j++){
            cd = gcd(cd, arr[j]);
            if(cd <= ans || cd == 1) 
                break;
        }
        if(cd > ans) ans = cd;
        arr[i] = temp;
    }
    
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        ans = 1000000000;
        input();
        solve();
        cout << "#" << t << " " << ans << endl;
    }
}