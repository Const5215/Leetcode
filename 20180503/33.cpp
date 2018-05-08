class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size()-1;
        if (L > R) return -1;
        if (target == nums[L]) return L;
        if (target == nums[R]) return R;
        if (target<nums[L] && target>nums[R]) return -1;
        if (target > nums[L]) {
            while(R-L > 1) {
                int m = (R-L)/2+L;
                if (nums[m] == target) return m;
                if (nums[m]<nums[0] || target<nums[m]) R = m;
                else L = m;
            }
            if (target == nums[L]) return L;
            if (target == nums[R]) return R;
            return -1;
        }
        else {
            while(R-L > 1) {
                int m = (R-L)/2+L;
                if (nums[m] == target) return m;
                if (nums[m]>nums[0] || target>nums[m]) L = m;
                else R = m;
            }
            if (target == nums[L]) return L;
            if (target == nums[R]) return R;
            return -1;           
        }
    }
};