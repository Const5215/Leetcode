class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        vector<string> lst;
        string ths;
        while(iss>>ths) lst.push_back(ths);
        if (lst.size() != pattern.size())
            return false;
        unordered_map<char,string> m;
        unordered_map<string,char> rm;
        for (int i = 0 ; i < pattern.size(); i++) {
            if (m[pattern[i]] == "")
                m[pattern[i]] = lst[i];
            else
                if (m[pattern[i]] != lst[i]) 
                    return false;
            if (rm[lst[i]] == '\0')
                rm[lst[i]] = pattern[i];
            else
                if (rm[lst[i]] != pattern[i])
                    return false;
        }
        return true;
    }
};