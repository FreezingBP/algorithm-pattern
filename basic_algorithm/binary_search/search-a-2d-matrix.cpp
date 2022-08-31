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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row, col; // hang, lie
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
//        else if(matrix.size() == 0 &&)
        row = matrix.size();
        col = matrix[0].size();

        int start = 0;
        int end = row*col - 1;
        int mid;
        for(; start + 1 < end;) {
            mid = start + (end - start)/2;
            if(matrix[mid/col][mid%col] < target)
                start = mid;
            else if(matrix[mid/col][mid%col] > target)
                end = mid;
            else
                return true;
        }
        if(matrix[start/col][start%col] == target)
            return true;
        else if(matrix[end/col][end%col] == target)
            return true;
        else
            return false;
    }
};
int main() {
//    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<vector<int>> matrix = {{1},{2},{3}};
//    for(int i = 0, j = 0; i < matrix.size(), j < matrix[0].size(); i++, j++)
//        cout << matrix[i][j] << " ";
//    cout << matrix.size() << endl;
//    cout << matrix[0].size() << endl;
    Solution result;
    cout << result.searchMatrix(matrix, 3) << endl;
}
