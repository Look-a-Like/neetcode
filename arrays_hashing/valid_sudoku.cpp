#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
public:
    bool isValidSudoku(vector<vector<char>>& board){
        vector<vector<bool>> rows(9, vector<bool>(9,false));
        vector<vector<bool>> columns(9, vector<bool>(9,false));
        vector<vector<bool>> boxes(9, vector<bool>(9,false));

        for(int i=0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j]=='.') continue;
                int num = board[i][j] - '1';
                int index = (i/3)*3 + (j/3);

                if(rows[i][num] || columns[j][num] || boxes[index][num]){
                    return false;
                }
                rows[i][num] = true;
                columns[j][num] = true;
                boxes[index][num] = true;
            }
        }
        return true;
    }
};

int main(){
    vector<vector<char>> board(9);
    for(int i=0;i<9;i++){
        vector<char> row;
        for(int j=0;j<9;j++){
            char inp;
            cin>> inp;
            row.push_back(inp);
        }
        board.push_back(row);
    }
    Solution s;
    bool ans = s.isValidSudoku(board);
    cout<< ans<<endl;
    return 0;
}