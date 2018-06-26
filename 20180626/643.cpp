class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int res = INT_MIN, sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];
        res = max(res,sum);
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i-k];
            res = max(res,sum);
        }
        return (double)res/k;
    }
};