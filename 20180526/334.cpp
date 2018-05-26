class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long long i = 1ll<<31, j = 1ll<<31;
        for (int x : nums) {
            if (x <= i) i = x;
            else if (x <= j) j = x;
            else return true;
        }
        return false;
    }
};