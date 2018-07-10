class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0;
        for (int i = 1; i < nums.size(); i++)
            s += nums[i];
        for (int i = 0; i < nums.size(); i++) {
            if (s == 0)
                return i;
            s -= nums[i];
            if (i < nums.size()-1)
                s -= nums[i+1];
        }
        return -1;
    }
};