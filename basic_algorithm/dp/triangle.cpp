#include <iostream>
#include <algorithm>
#include <hash_map>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0 || triangle[0].size() == 0)
            return 0;
        int row = triangle.size() - 1;
        int col = triangle[row].size() - 1;
        vector<vector<int>> dp(row, vector<int>(col, -1));

        dp[0][0] = triangle[0][0];
        for(int i = 1; i <= row; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0)
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if(j == i)
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
        }
        int min = *min_element(dp[row].begin(), dp[row].end());
        return min;
    }
};
// dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + tri[i][j]
// dp[0][0] = tri[i][j]
// when j == 0, dp[i][j] = dp[i-1][j] + tri[i][j]
// when j == i, dp[i][j] = dp[i-1][j-1] + tri[i][j]
// j < 0 || i < 0, dp[i][j] == MAX
int main() {
    Solution test;


}
