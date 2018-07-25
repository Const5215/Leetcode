class Solution {
public:
    bool validint(string now) {
        return now[0] != '0' || (now[0] == '0' && now.size() == 1);
    }
    bool validdec(string now) {
        return now.size() == 0 || now.back() != '0';
    }
    void makenum(vector<string>& tmp, string now) {
        for (int i = 1; i <= now.size();i++) {
            string x = now.substr(0,i), y = now.substr(i);
            if (validint(x) && validdec(y)) {
                if (y.size())
                    tmp.push_back(x+"."+y);
                else
                    tmp.push_back(x);
            }
        }
    }
    void makestr(vector<string>& res, string a, string b) {
        vector<string> res_a, res_b;
        makenum(res_a, a);makenum(res_b, b);
        for (int i = 0; i < res_a.size(); i++)
            for (int j = 0; j < res_b.size(); j++)
                res.push_back("("+res_a[i]+", "+res_b[j]+")");
    }
    vector<string> ambiguousCoordinates(string S) {
        S = S.substr(1, S.size()-2);
        vector<string> res;
        for (int i = 1; i < S.size(); i++)
            makestr(res, S.substr(0,i), S.substr(i));
        return res;
    }
};