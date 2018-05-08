class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int l = 0;
        bool f = 1;
        while(f) {
            if (l >= strs[0].size()) break;
            for (int i = 1; i < strs.size(); i ++) {
                if (l >= strs[i].size() || strs[i][l] != strs[0][l]) {
                    f = 0;
                    break;
                }
            }
            if (f) l++;
        }
        return strs[0].substr(0,l);
    }
};