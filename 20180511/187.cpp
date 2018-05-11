class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> hash;
        vector<string> res;
        if (s.length() < 10) return res;
        for (int i = 0; i <= s.length()-10; i++) {
            string now = s.substr(i,10);
            hash[now]++;
            if (hash[now] == 2) res.push_back(now);
        }  
        return res;
    }
};