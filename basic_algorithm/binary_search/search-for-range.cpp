class Solution {
public:
    /**
     * @param a: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &a, int target) {
        // write your code here
        int start = 0;
        int end = a.size()-1;
        int mid;
        vector<int> result = {-1,-1};
        if(a.size() == 0)
            return result;
        for(;start+1 < end;) {
            mid = start + (end-start)/2;
            if(a[mid] < target)
                start = mid;
            else if(a[mid] > target)
                end = mid;
            else if(a[mid] == target)
                end = mid; // to search left target position
        }
        // search left target
        if(a[start] == target)
            result[0] = start;
        else if(a[end] == target)
            result[0] = end;
        else {
            result[0] = -1;
            result[1] = -1;
            return result;
        }

        start = 0;
        end = a.size()-1;
        for(;start+1 < end;) {
            mid = start + (end-start)/2;
            if(a[mid] < target)
                start = mid;
            else if(a[mid] > target)
                end = mid;
            else if(a[mid] == target)
                start = mid; // to search right target position
        }
        // search right target
        if(a[end] == target)
            result[1] = end;
        else if(a[start] == target)
            result[1] = start;
        else {
            result[0] = -1;
            result[1] = -1;
            return result;
        }
        return result;
    }
};