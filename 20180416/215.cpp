class Solution {
public:
    int find(vector<int>& nums, int L, int R, int k) {
        int a = L, b = R;
        int ths = nums[L];
        while(R>L) {
            while(R > L&&nums[R] <= ths) R--;
            nums[L] = nums[R];
            while(R > L&&nums[L] >= ths) L++;
            nums[R] = nums[L];
        }
        nums[L] = ths;
        if (L==k) return nums[L];
        if (L>k) return find(nums, a, L-1, k);
        return find(nums, L+1, b, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums, 0, nums.size()-1, k-1);
    }
};