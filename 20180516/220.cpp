class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> s;
        long long border;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) s.erase(nums[i-k-1]);
            border = (long long)nums[i]-t;
            auto it = s.lower_bound(border);
            border = (long long)nums[i]+t;
            if (it != s.end() && *it <= border)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};