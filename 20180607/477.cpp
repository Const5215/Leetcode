class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> cnt(31);
        for (int x : nums) {
            for (int i = 0; i < 31; i++)
                if ((x>>i)&1)
                    cnt[i]++;
        }
        int res = 0;
        for (int x :nums) {
            for (int i = 0; i < 31; i++) 
                if ((x>>i)&1)
                    res += nums.size()-cnt[i];
                else 
                    res += cnt[i];
        }
        return res>>1;
    }
};