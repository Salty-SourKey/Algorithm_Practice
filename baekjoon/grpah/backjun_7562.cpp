#include <iostream>
#include <queue>

std::queue<std::pair<int,int>> move_queue;
std::queue<int> answer;
int move[301][301];
void update_move(int x, int y, int k, int n){
    if( x >= 0 && x < n && y >=0 && y < n){
        if(k+1 < move[x][y]){
            move[x][y] = k + 1;
            move_queue.push(std::make_pair(x,y));
        }
    }
}

int cal_min_move(int x, int y, int p, int q, int n){
    move_queue.push(std::make_pair(x,y));
    while(!move_queue.empty()){
        std::pair<int,int> temp = move_queue.front();
        move_queue.pop();
        if(temp.first == p && temp.second == q) return move[p][q];
        update_move(temp.first+2, temp.second+1, move[temp.first][temp.second], n);
        update_move(temp.first+1, temp.second+2, move[temp.first][temp.second], n);
        update_move(temp.first+2, temp.second-1, move[temp.first][temp.second], n);
        update_move(temp.first+1, temp.second-2, move[temp.first][temp.second], n);
        update_move(temp.first-2, temp.second+1, move[temp.first][temp.second], n);
        update_move(temp.first-1, temp.second+2, move[temp.first][temp.second], n);
        update_move(temp.first-2, temp.second-1, move[temp.first][temp.second], n);
        update_move(temp.first-1, temp.second-2, move[temp.first][temp.second], n);
        
    }
}

int main(){
    int n;
    std::cin >> n;
    while(n-- > 0){
        while(!move_queue.empty()) move_queue.pop();
        int l, x, y, p, q;
        std::cin >> l >> x >> y >> p >> q;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < l; j++)
                move[i][j] = 100000000;
        }
        move[x][y] = 0;
        answer.push(cal_min_move(x,y, p, q,l));
    }
    while(!answer.empty()){
        std::cout << answer.front();
        answer.pop();
        if(!answer.empty()) std::cout << std::endl;
    }
    return 0;
}

