class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int s = nums.size();
        if (s <= 2) return s;
        int res = 0,cnt = 0;
        for (int i = 1; i < s; i++) {
            if (nums[i] == nums[i-1]) cnt++;
            else cnt = 0;
            if (cnt < 2) nums[++res] = nums[i];
        }
        return res+1;
    }
};