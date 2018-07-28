class Solution {
public:
    string maskPII(string S) {
        string res = "";
        if (isalpha(S[0])) {
            istringstream iss(S);
            string tmp = "";
            getline(iss, tmp, '@');
            res += tolower(tmp.front());
            res += "*****";
            res += tolower(tmp.back());
            res += "@";
            iss>>tmp;
            for (int i = 0; i < tmp.size(); i++)
            res += tolower(tmp[i]);
        }
        else {
            string tmp = "";
            for (int i = 0; i < S.size(); i++)
                if (isdigit(S[i]))
                    tmp += S[i];
            if (tmp.size() > 10) {
                res += "+";
                for (int i = 0; i < tmp.size()-10; i++)
                    res += "*";
                res += "-";
            }
            res += "***-***-";
            res += tmp.substr(tmp.size()-4);
        }
        return res;
    }
};