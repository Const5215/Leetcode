class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        vector<int> c(26);
        for (char x : s1)
            c[x-'a']++;
        for (int i = 0; i < s1.length(); i++)
            c[s2[i]-'a']--;
        int k = s1.length();
        do {
            bool f = 1;
            for (int i = 0; i < 26; i++)
                if (c[i]) {
                    f = 0;
                    break;
                }
            if (f)
                return true;
            if (k < s2.length()) {
                c[s2[k-s1.length()]-'a']++;
                c[s2[k]-'a']--;
            }
            k++;
        }while(k <= s2.length());
        return false;
    }
};