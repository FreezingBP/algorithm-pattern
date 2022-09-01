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
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        for(;start + 1 < end;) {
            mid = start + (end-start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > nums[0] && (nums[mid] > target && target > nums[0]))
                end = mid;
            else if(nums[mid] > nums[0] && (nums[mid] < target))
                start = mid;
            else if(nums[mid] > nums[0] && target < nums[0])
                start = mid;
            else if(nums[mid] < nums[0] && target > nums[0])
                end = mid;
            else if(nums[mid] < nums[0] && (target < nums[0] && target && target > nums[mid]))
                start = mid;
            else
                end = mid;
        }
        if(nums[start] == target)
            return start;
        else if(nums[end] == target)
            return end;
        else
            return -1;
    }
};
int main() {
    Solution test;
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << test.search(nums,3) << endl;
}
