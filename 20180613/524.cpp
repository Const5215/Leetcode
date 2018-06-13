class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<int> l(d.size());
        for (char x : s) {
            for (int i = 0; i < d.size(); i++)
                if (l[i] < d[i].length() && d[i][l[i]] == x)
                    l[i]++;
        }
        int mx = -1;
        string res = "";
        for (int i = 0; i < d.size(); i++)
            if (l[i] == d[i].length() && mx <= l[i]) {
                if (mx < l[i] || (mx == l[i] && d[i] < res)) {
                    mx = l[i];
                    res = d[i];
                }
            }
        return res;
    }
};