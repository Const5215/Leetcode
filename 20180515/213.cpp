class Solution {
public:
    int find(vector<int>& nums, int l, int r) {
        int a = 0, b = 0;
        for (int i = l; i < r; i++) {
            int na = max(b+nums[i],a);
            int nb = max(a,b);
            a = na;
            b = nb;
        }
        return max(a,b);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(find(nums, 0, nums.size()-1),find(nums, 1, nums.size()));
    }
};