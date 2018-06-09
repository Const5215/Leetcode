class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> res;
        vector<vector<vector<int>>> tmp(nums.size());
        for (int i = 0;i < nums.size(); i++) {
            tmp[i].push_back(vector<int>(1,nums[i]));
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) continue;
                for (auto ths : tmp[j]) {
                    ths.push_back(nums[i]);
                    tmp[i].push_back(ths);
                }
            }
        }
        for (auto lst : tmp)
            for (auto ths : lst)
                if (ths.size() >= 2)
                    s.insert(ths);
        for (auto ths : s)
            res.push_back(ths);
        return res;
    }
};