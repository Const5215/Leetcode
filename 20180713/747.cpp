class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = -1, id = -1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > mx) {
                mx = nums[i];
                id = i;
            }
        for (int i = 0; i < nums.size(); i++)
            if (i != id && nums[i]*2 > mx)
                return -1;
        return id;
    }
};