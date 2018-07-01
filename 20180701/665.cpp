class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++){
            if (nums[i-1] <= nums[i])
                continue;
            int temp = nums[i-1];
            nums[i-1] = nums[i];
            if (is_sorted(nums.begin(),nums.end()))
                return true;
            nums[i-1]=nums[i]=temp;
            return is_sorted(nums.begin(),nums.end());
        }
        return true;
    }
};