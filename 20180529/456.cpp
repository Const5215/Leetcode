class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        multiset<int> s(nums.begin()+1,nums.end());
        int m = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            s.erase(s.find(nums[i]));
            auto it = s.upper_bound(m);
            if (it != s.end() && *it < nums[i]) return true;
            m = min(m, nums[i]);
        }
        return false;
    }
};