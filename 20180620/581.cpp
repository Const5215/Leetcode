class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ord = nums;
        sort(ord.begin(),ord.end());
        int res = 0, l = 0, r = nums.size()-1;
        while(l <= r && nums[l] == ord[l]) l++,res++;
        while(l < r && nums[r] == ord[r]) r--,res++;
        return nums.size()-res;
    }
};