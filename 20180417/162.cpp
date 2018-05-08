class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int L = 0 , R = nums.size()-1;
        while(R-L>1) {
            int m = (L+R)/2;
            if (nums[m] < nums[m+1]) L = m;
            else if (nums[m] < nums[m-1]) R = m;
            else return m;
        }
        return nums[L] > nums[R] ? L : R;
    }
};