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
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        if(nums.size() == 1) {
            if(nums[0] == target)
                return true;
            else
                return false;
        }
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
            if(nums[mid] == target || nums[end] == target || nums[start] == target)
                return true;
            else if(nums[mid] > nums[start] && (nums[mid] > target && target > nums[start]))
                end = mid;
            else if(nums[mid] > nums[start] && (nums[mid] < target))
                start = mid;
            else if(nums[mid] > nums[start] && target < nums[start])
                start = mid;
            else if(nums[mid] < nums[start] && target > nums[start])
                end = mid;
            else if(nums[mid] < nums[start] && (target < nums[start] && target && target > nums[mid]))
                start = mid;
            else
                end = mid;
        }
        if(nums[start] == target)
            return true;
        else if(nums[end] == target)
            return true;
        else
            return false;
    }
};
int main() {
    Solution test;
    vector<int> nums = {2,6,5,0,0,1,2};
    cout << test.search(nums,0) << endl;
}
