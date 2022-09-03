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
    bool canJump(vector<int>& nums) {
        int right = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(right < i)
                return false;
            right = max(right, i + nums[i]);

        }
        return true;
    }
};
// 0 1 2 3 4
// 2,3,1,1,4
int main() {
    Solution test;
    vector<int> nums{2,3,1,1,4};
    cout << test.canJump(nums);
}
