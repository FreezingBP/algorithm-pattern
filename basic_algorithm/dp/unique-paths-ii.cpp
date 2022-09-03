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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col,0));
        if(obstacleGrid[0][0] == 1)
            return 0;
        dp[0][0] = 1;
        for(int i = 1; i < row; i++) {
            if(obstacleGrid[i][0] != 1)
                dp[i][0] = 1;
            else
                break;
        }
        for(int j = 1; j < col; j++) {
            if(obstacleGrid[0][j] != 1)
                dp[0][j] = 1;
            else
                break;
        }
        for(int i = 1; i < row; i++) {
            for(int j = 1; j < col; j++) {
                if(obstacleGrid[i][j] == 1)
                    continue;
                else {
                    if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] != 1)
                        dp[i][j] = dp[i][j-1];
                    else if(obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] == 1)
                        dp[i][j] = dp[i-1][j];
                    else if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 1)
                        continue;
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];

                }
            }
        }
        return dp[row-1][col-1];
    }
};

int main() {
    Solution test;
}
