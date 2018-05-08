class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> m;
        int L = 1<<nums.size();
        for (int i = 0; i < L; i++) {
            vector<int> ths;
            for (int j = 0; j < nums.size(); j++)
                if ((i>>j)&1) ths.push_back(nums[j]);
            m.insert(ths);
        }
        vector<vector<int>> res(m.begin(), m.end());
        return res;
    }
};