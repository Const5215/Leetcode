class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        istringstream iss_a(A), iss_b(B);
        string tmp;
        unordered_map<string, int> m;
        while(iss_a>>tmp) m[tmp]++;
        while(iss_b>>tmp) m[tmp]++;
        vector<string> res;
        for (auto x : m)
            if (x.second == 1)
                res.push_back(x.first);
        return res;
    }
};