#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int minMove[51][51];
vector<pair<int,int>> v_move;

class MazeMaker{
public:
    
    int longestPath(vector<string> maze, int startRow, int startCol,
                    vector<int> moveRow, vector<int> moveCol){
        for(int i = 0; i < moveRow.size(); ++i) v_move.push_back(make_pair(moveRow[i],moveCol[i]));
        return bfs(maze, startRow, startCol);
    }
    int bfs(vector<string> maze, int startRow, int startCol){
        queue<pair<int,int>> q;
        int result = 0;
        q.push(make_pair(startRow,startCol));
        while(!q.empty()){
            int x_pos = q.front().first;
            int y_pos = q.front().second;
            q.pop();
            for(int i = 0; i < v_move.size(); ++i){
                int x_next = x_pos+v_move[i].first;
                int y_next = y_pos+v_move[i].second; 
                if(x_next < maze.size() && x_next >= 0 && y_next < maze[0].length() && y_next >= 0 && maze[x_next][y_next] == '.'){
                    if(minMove[x_next][y_next] == 0 && !(x_next == startRow && y_next == startCol)){
                        minMove[x_next][y_next] = minMove[x_pos][y_pos]+1;
                        q.push(make_pair(x_next,y_next));
                    }
                }
            }
        }
        for(int i = 0; i < maze.size(); ++i){
            for (int j = 0; j < maze[0].length(); ++ j){
                if(maze[i][j] == '.'){
                    if(minMove[i][j] == 0 && !(i == startRow && j == startCol)){
                        return -1;
                    }
                    result = max(result, minMove[i][j]);
                }
            }
        }
        return result;   
    }
};
int main(){
    vector<string> maze;
    string temp;
    int n;
    int k;
    int startRow, startCol;
    cin >> n >> k >> startRow >> startCol;
    int row;
    int col;
    vector<int> moveRow;
    vector<int> moveCol;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        maze.push_back(temp);
    }
    for(int i = 0; i < k; ++i){
        cin >> row >> col;
        moveRow.push_back(row);
        moveCol.push_back(col);
    }
    MazeMaker mm;
    cout << mm.longestPath(maze, startRow, startCol, moveRow, moveCol);
    return 0;
}