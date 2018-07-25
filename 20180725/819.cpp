class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        istringstream iss(paragraph);
        string now;
        map<string, int> m;
        set<string> s;
        for (string banword : banned)
            s.insert(banword);
        while(iss>>now) {
            string word = "";
            for (char x : now)
                if (isalpha(x))
                    word = word + (char)tolower(x);
            m[word]++;
        }
        int mx = 0;string res = "";
        for (auto it : m) {
            if (s.find(it.first) == s.end() && it.second > mx) {
                mx = it.second;
                res = it.first;
            }
        }
        return res;
    }
};