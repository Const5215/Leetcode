class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = nums.size() ? nums[0] : 0;
        for (int i = 1; i < nums.size(); i++) {
            int tmp = a;
            a = max(tmp, b);
            b = max(b, tmp+nums[i]);
        }
        return max(a,b);
    }
};