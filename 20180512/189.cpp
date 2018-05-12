class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(k != 0){
            int m = nums.size() - k;
            while(m){
                for(int i = m - 1; 0 <= i; i--)
                    swap(nums[i], nums[i+k]);
                m %= k;
                k -= m;
            }
        }
    }
};