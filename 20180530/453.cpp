class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int mn = nums[0], res = 0;
        for (int i : nums) mn = min(mn, i);
        for (int i : nums) res += i-mn;
        return res;
    }
};