class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> tot(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (k)
                tot[i] = ((i?tot[i-1]:0)+nums[i])%k;
            else
                tot[i] = (i?tot[i-1]:0)+nums[i];
        }
        unordered_map<int,int> m;
        m[0] = -1;
        for (int i = 0; i < tot.size(); i++) {
            if (m.find(tot[i]) != m.end()) {
                if (i-m[tot[i]] > 1)
                    return true;
            }else{
                m[tot[i]] = i;
            }
        }
        return false;
    }
};