class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int mx_p = nums[0], mn_p = nums[0],mx,mn;
        int res = mx_p;
        for (int i = 1; i < nums.size(); i++) {
            mx = max(nums[i],nums[i] > 0 ? mx_p*nums[i] : mn_p*nums[i]);
            mn = min(nums[i],nums[i] > 0 ? mn_p*nums[i] : mx_p*nums[i]);
            mx_p = mx;
            mn_p = mn;
            if (res < mx) res = mx;
        }
        return res;
    }
};