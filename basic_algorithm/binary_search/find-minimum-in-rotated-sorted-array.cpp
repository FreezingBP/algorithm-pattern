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
            mid = start + (end - start)/2;
            if(nums[mid] > nums[end])
                start = mid;
            else if(nums[mid] <= nums[end])
                end = mid;
        }
        if(nums[start] < nums[end])
            return nums[start];
        else
            return nums[end];
    }
};
int main() {
    Solution test;
    vector<int> nums = {9,0,2,7,8};
    cout << test.findMin(nums) << endl;
}
