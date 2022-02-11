#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Contestant{
    private:
        int team_num;
        bool flag[10] = {0,};             //해당 문제 Correct 받았는지 확인
        int correct_num = 0;              //맞춘 문제 개수
        int incorrect_num[10] = {0,};     //해당 문제 Incorrect 받은 횟수
        int penalty_time = 0;             //Total Penalty Time

    public:
        Contestant(){                     //일단 Team_num = -1로 초기화
            this->team_num = -1;
        }

        void set_team_num(int num){
            if(team_num == -1)
                this->team_num = num;
        }

        void incorrect_count(int num){    //해당 문제 틀리면 incorrect_num[num]++
            if(!this->flag[num])
                this->incorrect_num[num]++;
        }
 
        void accept(int num, int k){                           //해당 문제 맞추면
            if(!this->flag[num]){                              //처음 맞춘 경우에만..
                this->penalty_time+=k+20*incorrect_num[num];   //Penalty Time Update
                this->correct_num++;                           //맞춘 횟수 Update
                this->flag[num] = true;                        //다시 Check 안되게 Flag Update
            }
        }

        void print(){
            if(this->team_num != -1)
                cout << team_num << " " << correct_num << " " << penalty_time << endl;
        }

        bool operator <(Contestant &cont){                     // < Operator Overriding
            if(cont.correct_num == this->correct_num){
                if(this->penalty_time == cont.penalty_time){
                    return this->team_num < cont.team_num;
                }
                else return this->penalty_time < cont.penalty_time;
            }
            else return this->correct_num > cont.correct_num;
        }
};


int main(){
    int N;
    cin >> N;
    cin.ignore();
    cin.ignore();                             //Case Number 이후 Enter 2번 무시
    while(N--){
        int team_num, problem, t;
        char L;
        string input;
        vector<Contestant> arr(101);
        for(int i = 0; i <= 100; i++)
            arr.push_back(Contestant());
        //일단 getline으로 한 줄을 Input으로 받고 더이상 Input 없을때까지 받음
        while(getline(cin,input) && input.length() != 0){
            //input을 parse하여 알맞은 변수에 넣어줌
            istringstream in(input);
            in >> team_num >> problem >> t >> L;
            
            arr[team_num].set_team_num(team_num);
            if(L == 'C') arr[team_num].accept(problem, t);
            else if(L == 'I') arr[team_num].incorrect_count(problem);
        }
        
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++)
            arr[i].print();

        if(N) cout << endl;
    }
    return 0;
}
