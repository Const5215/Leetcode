class Solution {
public:
    int find(vector<int>& s, int x) {
        if (s[x] == x)
            return x;
        else
            return s[x] = find(s, s[x]);
    }
    void uset(vector<int>& s, int a, int b) {
        s[find(s, a)] = s[find(s, b)];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> s(accounts.size());
        for (int i = 0; i < accounts.size(); i++)
            s[i] = i;
        map<string, int> m;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (m.count(accounts[i][j]))
                    uset(s, i, m[accounts[i][j]]);
                else
                    m[accounts[i][j]] = i;
            }
        }
        vector<vector<string>> res;
        for (int i = 0; i < accounts.size(); i++)
            if (find(s, i) != i) {
                for (int j = 1; j < accounts[i].size(); j++)
                    accounts[find(s, i)].push_back(accounts[i][j]);
            }
        for (int i = 0; i < accounts.size(); i++)
            if (find(s, i) == i) {
                res.push_back(accounts[i]);
                sort(res[res.size()-1].begin()+1, res[res.size()-1].end());
                auto it = unique(res[res.size()-1].begin(), res[res.size()-1].end());
                res[res.size()-1].resize(it-res[res.size()-1].begin());
            }
        return res;
    }
};