class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                continue;
            int p = 0;
            for (int j = i+1; j < nums.size()-1; j++) {
                p = max(p, j+1);
                while(p < nums.size() && nums[p] < nums[i]+nums[j])
                    p++;
                res += p-j-1;
            }
        }
        return res;
    }
};