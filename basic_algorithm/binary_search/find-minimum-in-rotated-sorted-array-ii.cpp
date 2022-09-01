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
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        for(;start + 1 < end;) {
            for(;start < end;) {
                if(nums[start] == nums[start+1])
                    start++;
                else
                    break;
            }
            for(;start< end;) {
                if(nums[end] == nums[end-1])
                    end--;
                else break;
            }
            mid = start + (end-start)/2;
            if(nums[mid] <= nums[end])
                end = mid;
            else
                start = mid;
        }
        if(nums[start] < nums[end])
            return nums[start];
        else
            return nums[end];
    }
};
int main() {
    Solution test;
    vector<int> nums = {2,2,2,0,1};
    cout << test.findMin(nums) << endl;
}
