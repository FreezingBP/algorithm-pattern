#include <iostream>
#include <hash_map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < row; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j = 1; j < col; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];

        return dp[row-1][col-1];
    }
};
// dp[0][0] = grid[0][0]
// when i == grid.row-1 && j == 0, dp[i][j] = dp[i-1][j] + grid[i][j]
// when i == 0 && j != 0, dp[i][j] = dp[i][j-1] + grid[i][j]
int main() {
    Solution test;
    vector<vector<int>> grid(3,vector<int>(3));
    grid[0] = {1,3,1};
    grid[1] = {1,5,1};
    grid[2] = {4,2,1};
    cout << test.minPathSum(grid);

}
