// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        int mid;
        for(;start + 1 < end;) {
            mid = start + (end - start)/2;
            if(isBadVersion(mid) == false)
                start = mid;
            else
                end = mid;
        }
        if(isBadVersion(start) == true)
            return start;
        else
            return end;
    }
};