class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> dat;
        for (string x : words) {
            int now = 0;
            for (char i : x)
                now  |= (1<<(i-'a'));
            dat.push_back(now);
        }
        int res = 0;
        for (int i = 0; i < dat.size(); i++)
            for (int j = i+1; j < dat.size(); j++)
                if ((dat[i]&dat[j]) == 0)
                    res = max(res, (int)words[i].length()*(int)words[j].length());
        return res;
    }
};