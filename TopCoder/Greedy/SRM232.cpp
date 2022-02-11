#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

double profit[51][2];
class StockHistory{
public:
    vector<string> split(string input, char delimiter){
        vector<string> answer;
        stringstream ss(input);
        string temp;
        while (getline(ss, temp, delimiter)) {
            answer.push_back(temp);
        }
        return answer;
    }
    vector<vector<double>> stodo(vector<string> stockPrices){
        vector<vector<double>> price;
        for(int i = 0; i < stockPrices.size(); ++i){
            vector<string> temp = split(stockPrices[i], ' ');
            vector<double> d;
            for(int j = 0; j < temp.size(); ++j) d.push_back((double)stoi(temp[j]));
            price.push_back(d);
        }
        return price;
    };
    int maximumEarnings(int initialInvestment, int monthlyContribution, vector<string> stockPrices){
        vector<vector<double>> price = stodo(stockPrices);
        int N = price.size();
        int stock_num = price[0].size();
        double money, ans = 0.0;
        double max_profit = 0.0;
        for(int i = 0; i < N-1; ++i){
            for(int j = 0; j < stock_num; ++j){
                price[i][j]=price[N-1][j]/price[i][j] - 1;
            }
            sort(price[i].begin(), price[i].end(), greater<>());
        }
        for(int i = N-2; i >= 0; --i){
            if(i == 0) money = initialInvestment;
            else money = monthlyContribution;

            if(max_profit <= price[i][0] && price[i][0] > 0) max_profit = price[i][0];
            ans += money * max_profit;

        }
        return ans;
    }

};
int main(){
    StockHistory s;
    vector<string> a;
    a.push_back("40 50 60");
    a.push_back("37 48 55");
    a.push_back("100 48 50");
    a.push_back("100 48 47");
    a.push_back("110 50 52");
    a.push_back("110 50 52");
    a.push_back("110 51 54");
    a.push_back("109 49 53");
    cout << s.maximumEarnings(100,20,a);
    return 0;
}