#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;
        while(row<n && col>=0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(target > matrix[row][col]){
                row++;
            }else{
                col--;
            }
        }
        return false;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int target;
    cin>> target;
    Solution s;
    cout<< s.searchMatrix(matrix, target)<<endl;
    return 0;
}