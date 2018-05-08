class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(lower_bound(nums.begin(), nums.end(), target)-nums.begin());
        if (nums.size() == 0 || res[0] == nums.size() || nums[res[0]] != target) {
            res[0] = -1;
            res.push_back(-1);
            return res;
        }
        res.push_back(upper_bound(nums.begin(), nums.end(), target)-nums.begin()-1);
        return res;
    }
};