class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for (int L = 0, R = 0; L < nums.size();) {
            R = L+1;
            while(R < nums.size() && nums[R] == nums[R-1] + 1) R++;
            string ths = to_string(nums[L]);
            if (R != L+1) {
                ths += "->";
                ths += to_string(nums[R-1]);
            }
            res.push_back(ths);
            L = R;
        }
        return res;
    }
};