class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, pair<string, string>>> lst,valid;
        for (int i = 0; i < indexes.size(); i++)
            lst.push_back({indexes[i],{sources[i], targets[i]}});
        sort(lst.begin(),lst.end());
        for (auto now : lst)
            if (S.substr(now.first, now.second.first.size()) == now.second.first)
                valid.push_back({now.first, {now.second.first, now.second.second}});
        int p = 0, i = 0;
        string res = "";
        while(p < S.size())
            if (i < valid.size()) {
                if (p != valid[i].first) {
                    res += S[p];
                    p++;
                }
                else {
                    res += valid[i].second.second;
                    p += valid[i].second.first.size();
                    i++;
                }
            }
            else {
                res += S[p];
                p++;                
            } 
        return res;
    }
};