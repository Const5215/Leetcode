class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> f(50000), l(50000), r(50000);
        for (int i = 0; i < nums.size(); i++)
            if (++f[nums[i]] == 1)
                l[nums[i]] = r[nums[i]] = i;
            else
                r[nums[i]] = i;
        int res = INT_MAX, fre = 0;
        for (int i = 0; i < 50000; i++)
            if (f[i] > fre) {
                fre = f[i];
                res = r[i]-l[i]+1;
            }
            else if (f[i] == fre && r[i]-l[i]+1 < res)
                res = r[i]-l[i]+1;
        return res;
    }
};