class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p = nums.size()-1;
        for (; p > 0 && nums[p] <= nums[p-1]; p--);
        if (p == 0) {
            sort(nums.begin(), nums.end());
            return;
        }
        p--;
        int q = nums.size()-1;
        for (; q > p && nums[q] <= nums[p]; q--);
        swap(nums[p], nums[q]);
        sort(nums.begin()+p+1, nums.end());
    }
};