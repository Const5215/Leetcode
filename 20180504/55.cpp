class Solution {
public:
    bool canJump(vector<int>& nums) {
        int now = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (now < i) return false;
            now = max(now, i+nums[i]);
        }
        return true;
    }
};