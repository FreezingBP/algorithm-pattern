class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        for( ; start + 1 < end;) {
            mid = start + (end - start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                start = mid;
            else if(nums[mid] > target)
                end = mid;
        }
        if(nums[start] == target)
            return start;
        else if(nums[end] == target)
            return end;
        
        return -1;
    }
};