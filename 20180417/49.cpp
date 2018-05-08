class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for (string ths : strs) {
            string tmp = ths;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(ths);
        }
        vector<vector<string>> res;
        for (auto it : m)
            res.push_back(it.second);
        return res;
    }
};