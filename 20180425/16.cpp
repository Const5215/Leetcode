class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size()-2; i++) {
            int j = i+1;
            int R = nums.size()-1;
            while (j < R) {
                int sum = nums[i]+nums[j]+nums[R];
                if (abs(sum-target) < abs(res-target))
                    res = sum;
                if (sum < target) j++;
                else R--;
            }
        }
        return res;        
    }
};