class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for (char x : s) {
            m[x]++;
        }
        int f = 0, c = 0;
        for (auto it : m) {
            c += it.second/2;
            if (it.second&1) f = 1;
        }
        return c*2+f;
    }
};