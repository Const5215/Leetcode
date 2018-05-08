class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0, R = nums.size()-1;
        while(nums[L] >= nums[R]) {
            int mid = L+(R-L)/2;
            if (nums[L] == nums[R] && nums[L] == nums[mid])
                return findlinear(nums, L ,R);
            if (nums[mid] <= nums[R]) R = mid;
            else L = mid+1;
        }
        return nums[L];
    }
    int findlinear(vector<int>& nums, int L, int R) {
        int res = nums[L];
            for (int i = L; i <= R; i++)
                res = min(res,nums[i]);
        return res;
    }
};