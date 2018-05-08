class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        find(digits, 0, res, "");
        return res;
    }
private:
    string ind[8] ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void find(string& n, int i, vector<string>& res, string ths) {
        if (i == n.length()) {
            if (ths != "")
                res.push_back(ths);
            return;
        }
        if (n[i] == '1') find(n,i+1,res,ths);
        for (int t = 0; t < ind[n[i]-'2'].length(); t++)
            find(n, i+1, res, ths + ind[n[i]-'2'][t]);
    }
};