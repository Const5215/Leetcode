class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, now = 1, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            now *= nums[i];
            while(i >= l && now >= k) {
                now /= nums[l];
                l++;
            }
            res += i-l+1;
        }
        return res;
    }
};