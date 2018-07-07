class Solution {
public:
    bool find(vector<int>& nums, vector<bool>& vis, int now) {
        if (now == 0)
            return true;
        for (int i = 0; i < nums.size(); i++)
            if (vis[i] == 0 && nums[i] <= now) {
                vis[i] = 1;
                if (find(nums, vis, now-nums[i]))
                    return true;
                vis[i] = 0;
            }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<bool> vis(nums.size());
        int tot = 0;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            tot += nums[i];
        if (tot%k != 0)
            return false;
        int cnt = tot/k;
        for (int i= 0; i < nums.size(); i++)
            if (nums[i] > cnt)
                return false;
        for (int i = 0; i < k; i++)
            if (find(nums, vis, cnt) == false)
                return false;
        return true;
    }
};