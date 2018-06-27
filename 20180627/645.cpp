class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i+1) continue;
            int now = nums[i];
            nums[i] = 0;
            while(nums[now-1] && nums[now-1] != now) {
                int nxt = nums[now-1];
                nums[now-1] = now;
                now = nxt;
            }
            if (nums[now-1])
                res.push_back(now);
            else
                nums[now-1] = now;
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0) {
                res.push_back(i+1);
                return res;
            }
    }
};