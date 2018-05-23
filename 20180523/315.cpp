class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> now;
        for (int i = nums.size()-1; i >= 0; i--) {
            auto it = lower_bound(now.begin(), now.end(), nums[i]);
            res[i] = it - now.begin();
            now.insert(it, nums[i]);
        }
        return res;
    }
};