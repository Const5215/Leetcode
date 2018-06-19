class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int k = i, now = 0;
            while(nums[k] != -1) {
                int n = nums[k];
                nums[k] = -1;
                now++;
                k = n;
            }
            res = max(res, now);
        }
        return res;
    }
};