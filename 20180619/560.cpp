class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int s = 0,res = 0;
        m[0]++;
        for (int x : nums) {
            s += x;
            res += m[s-k];
            m[s]++;
        }
        return res;
    }
};