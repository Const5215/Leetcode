class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); i++) {
            int p = m[nums[i]];
            if (p && i-p < k) 
                return true;
            m[nums[i]] = i+1;
        }
        return false;
    }
};