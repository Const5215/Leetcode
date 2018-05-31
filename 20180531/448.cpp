class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int now = i+1;
            if (nums[now-1] != now) {
                int tmp = nums[now-1];
                nums[now-1] = 0;
                now = tmp;
            }
            while(now && nums[now-1] != now) {
                int nxt = nums[now-1];
                nums[now-1] = now;
                now = nxt;
            }
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i+1)
                res.push_back(i+1);
        return res;
    }
};