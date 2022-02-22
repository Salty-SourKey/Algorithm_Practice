#include <iostream>
#include <math.h>

using namespace std;

int T, N;
double dist[11];
double mass[11];
double ans[11];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> dist[i];
    
    for(int i = 0; i < N; i++)
        cin >> mass[i];
    
}

double force_sum(int from, int to, double point){
    double sum = 0.0;
    for(int i = from; i <= to; i++)
        sum += mass[i] / ((point - dist[i])*(point - dist[i]));
    
    return sum;
}

double binary_search(double a, double b, int idx, double prev){
    double c = (a+b) / 2;
    double check_a = force_sum(0, idx, c);
    double check_b = force_sum(idx+1, N-1, c);
    if(abs(prev-c) < 0.000000000001 || check_a == check_b) return c;
    else if(check_a > check_b)
        return binary_search(c, b, idx, c);
    else 
        return binary_search(a, c, idx, c);
    
}


void solve(){
    for(int i = 0; i < N-1; i++){
        ans[i] = binary_search(dist[i], dist[i+1], i, 0);    
    }
}

int main(){
    cin >> T;
    cout<<fixed;
    cout.precision(10);
    for(int t = 1; t <= T; t++){
        input();
        solve();
        for(int i = 0; i < N-1; i++){
            if(!i && t)
                cout << endl << "#" << t << " ";
            cout << " " << ans[i];
        }
    }
}