#include <iostream>
using namespace std;

class AutoLoan{
public:
    double calc(double price, double monthlyPayment, int loanTerm, double interest){
        double ans = price;
        for(int i = 0; i < loanTerm; ++i) ans = ans*(1+interest/100) - monthlyPayment;
        return ans;
        
    }
    double interestRate(double price, double monthlyPayment, int loanTerm){
        double a = 0;
        double b = 100;
        double c = 100;
        double temp;
        while(true)
        {
            temp = calc(price, monthlyPayment, loanTerm, c); 
            if(-(0.000000001) <= temp && temp <= 0.000000001 )
                break;
            if(temp > 0) b = c;
            else a = c;
            c = (a + b)/2;
            
        }
        return c*12;
    }

};
int main(){
    AutoLoan a;
    cout << a.interestRate(2000, 510, 4);
    return 0;
}