class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int now = 0, res = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i]) now++;
            else now--;
            if (m.find(now) != m.end())
                res = max(res, i-m[now]);
            else
                m[now] = i;
        }
        return res;
    }
};