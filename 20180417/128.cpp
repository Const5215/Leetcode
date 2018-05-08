class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int i : nums) {
            if (s.find(i) == s.end()) continue;
            s.erase(i);
            int L = i-1, R = i+1;
            while(s.find(L) != s.end()) {s.erase(L);L--;}
            while(s.find(R) != s.end()) {s.erase(R);R++;}
            L++;R--;
            res = max(res, R-L+1);
        }
        return res;
    }
};