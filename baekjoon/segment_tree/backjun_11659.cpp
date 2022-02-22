    #include <iostream>
    using namespace std;

    int dp[100001];
    int input[100001];
    int N;
    int M;

    void init(){
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
    }

    int main(){
        init();
        int left, right;
        cin >> N >> M;
        cin >> input[1];
        dp[1] = input[1];

        for(int i = 2; i <= N; i++){
            cin >> input[i];
            dp[i] = dp[i-1] + input[i];
        }

        while(1){
            if(M <= 0) break;
            cin >> left >> right;
            cout << dp[right] - dp[left-1] << "\n";
            M--;
        }

    }
